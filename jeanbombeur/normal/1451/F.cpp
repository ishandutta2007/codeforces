#include <iostream>
#include <cstdio>
using namespace std;

// <|_|>

const int MAX_LIGNES = 100;

int Val[MAX_LIGNES][MAX_LIGNES];

int nbLignes, nbColonnes;

void Read() {
    scanf("%d%d", &nbLignes, &nbColonnes);
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbColonnes; j ++)
        {
            scanf("%d", &Val[i][j]);
        }
    }
    for (int d = 0; d < nbLignes + nbColonnes - 1; d ++)
    {
        int sum = 0;
        for (int i = 0; i < nbLignes; i ++)
        {
            if (0 <= d - i && d - i < nbColonnes)
            {
                sum ^= Val[i][d - i];
            }
        }
        if (sum != 0)
        {
            printf("Ashish\n");
            return;
        }
    }
    printf("Jeel\n");
    return;
}

int main() {
    int nbTests;
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}