#include <iostream>
#include <cstdio>
using namespace std;

// <|_|>

const int MAX_VALEURS = (1000 * 1000);

int Occ[27][2];

int nbValeurs, taille, nbTests;

void Read() {
    scanf("%d%d\n", &nbValeurs, &taille);
    char x;
    for (int i = 0; i < 27; i ++)
    {
        Occ[i][0] = 0;
        Occ[i][1] = 0;
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%c", &x);
        Occ[x - 'a'][0] ++;
    }
    scanf("\n");
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%c", &x);
        Occ[x - 'a'][1] ++;
    }
    scanf("\n");
    for (int i = 0; i < 26; i ++)
    {
        int d = Occ[i][0] - Occ[i][1];
        if (d > 0 && d % taille == 0)
        {
            Occ[i][0] -= d;
            Occ[i + 1][0] += d;
            d = 0;
        }
        if (d != 0)
        {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
    return;
}

int main() {
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}