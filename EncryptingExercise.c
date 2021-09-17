#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int KEYLENGTH = 26;
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int letters[KEYLENGTH];

int main(int argc, string argv[])
{
    //Check for valid number of commands and characters

    if (argc != 2 || strlen(argv[1]) != KEYLENGTH)
    {
        printf("Invalid command.\n");
        return 1;
    }

    //Check for non-alphabetical characters
    for (int i = 0; i < KEYLENGTH; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only letters.\n");
            return 1;
        }
    }

    //Convert key to uppercase
    for (int u = 0; u < KEYLENGTH; u++)
    {
        argv[1][u] = toupper(argv[1][u]);
    }

    //Check for repeated characters

    for (int i = 0; i < KEYLENGTH; i++)
    {
        // Check for repeated letters
        for (int j = 0; j < KEYLENGTH; j++)
        {
            if (argv[1][i] == letters[j])
            {
                printf("Key must not contain repeated letters.\n");
                return 1;
            }
        }
        letters[i] = argv[1][i];
    }


    //Prompt for plaintext
    string plaintext = get_string("plaintext: ");
    int plainTextLength = strlen(plaintext);
    char ciphertext[plainTextLength + 1];

    //Convert plaintext into chipertext
    for (int i = 0; i < plainTextLength; i++)
    {
        if (isupper(plaintext[i]) != 0)
        {
            for (int j = 0; j < KEYLENGTH; j++)
            {
                if (plaintext[i] == ALPHABET[j])
                {
                    ciphertext[i] = argv[1][j];
                    break;
                }
            }
        }
        else if (islower(plaintext[i]) != 0)
        {
            for (int j = 0; j < strlen(ALPHABET); j++)
            {
                if (plaintext[i] == tolower(ALPHABET[j]))
                {
                    ciphertext[i] = tolower(argv[1][j]);
                    break;
                }
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    //Add null char to make it a string
    ciphertext[plainTextLength] = '\0';

    //Print ciphertext
    printf("ciphertext: %s\n", ciphertext);
    //Return success
    return 0;
}