#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//    <|_|>

//   The hardest choices require the strongest wills

const int MAX_VALEURS = (100 * 1000);
const int MAX_LIGNES = (50);

int Val[MAX_VALEURS];

char Grille[MAX_LIGNES][MAX_LIGNES];

int nbLignes, nbColonnes;

void Read() {
    scanf("%lld %lld\n", &nbLignes, &nbColonnes);
    int r = -1, w = -1;
    bool exists = true;
    for (int i = 0; i < nbLignes; i ++)
    {
        scanf("%s", Grille[i]);
        for (int j = 0; j < nbColonnes; j ++)
        {
            if (Grille[i][j] == 'R')
            {
                if (r >= 0 && ((i + j) & 1) != r)
                    exists = false;
                r = (i + j) & 1;
            }
            if (Grille[i][j] == 'W')
            {
                if (w >= 0 && ((i + j) & 1) != w)
                    exists = false;
                w = (i + j) & 1;
            }
        }
    }
    if (r >= 0 && r == w)
        exists = false;
    if (!exists)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    if (min(r, w) < 0)
    {
        if (r < 0 && w < 0)
            r = 0, w = 1;
        if (r < 0)
            r = w ^ 1;
        if (w < 0)
            w = r ^ 1;
    }
    for (int i = 0; i < nbLignes; i ++)
    {
        for (int j = 0; j < nbColonnes; j ++)
        {
            if (((i + j) & 1) == r)
                printf("R");
            else
                printf("W");
        }
        printf("\n");
    }
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}