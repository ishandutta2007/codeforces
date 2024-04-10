#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//     <|_|>

const int MAX_LIGNES = (500);

int Grille[MAX_LIGNES][MAX_LIGNES];

int nbLignes, nbColonnes;

void Read() {
    scanf("%d%d\n", &nbLignes, &nbColonnes);
    int ans = 0;
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbColonnes; j ++)
        {
            char x;
            scanf("%c", &x);
            Grille[i][j] = 0;
            if (x == '*')
            {
                Grille[i][j] = 1;
            }
        }
        scanf("\n");
    }
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = nbColonnes - 2; j >= 0; j --)
        {
            if (Grille[i][j] == 1)
            {
                Grille[i][j] += Grille[i][j + 1];
            }
        }
    }
    for (int d = 0; d < nbLignes + nbColonnes - 1; d ++)
    {
        int cur = -1;
        int nb = 0;
        for (int i = 0; i < nbLignes; i ++)
        {
            if (d - i >= 0 && d - i < nbColonnes)
            {
                if (Grille[i][d - i] >= cur + 2)
                {
                    cur += 2;
                    nb ++;
                }
                else
                {
                    cur = Grille[i][d - i];
                    if (cur % 2 == 0)
                    {
                        cur --;
                    }
                    nb = (cur + 1) / 2;
                }
                ans += nb;
            }
        }
    }
    printf("%d\n", ans);
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