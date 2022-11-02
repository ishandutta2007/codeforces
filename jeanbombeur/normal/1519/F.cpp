#include <iostream>
#include <cstdio>
using namespace std;

//   <|_|>

const int MAX_MASK = 15625;
const int INFINI = (1000 * 1000 * 1000);
const int MAX_COFFRES = 7;

int Pow[MAX_COFFRES];

int DP[MAX_COFFRES][MAX_COFFRES][MAX_COFFRES][MAX_MASK];

int Coffres[MAX_COFFRES];
int Cles[MAX_COFFRES];
int Verrous[MAX_COFFRES][MAX_COFFRES];

int nbCoffres, nbCles;

int GetIndex(int a, int id) {
    return (a / Pow[id]) % 5;
}

void Read() {
    scanf("%d%d", &nbCoffres, &nbCles);
    for (int i = 0; i < nbCoffres; i ++)
    {
        scanf("%d", &Coffres[i]);
    }
    for (int i = 0; i < nbCles; i ++)
    {
        scanf("%d", &Cles[i]);
    }
    for (int i = 0; i < nbCoffres; i ++)
    {
        for (int j = 0; j < nbCles; j ++)
        {
            scanf("%d", &Verrous[i][j]);
        }
    }
    Pow[0] = 1;
    for (int i = 1; i <= nbCoffres; i ++)
    {
        Pow[i] = 5 * Pow[i - 1];
    }
    return;
}

void Solve() {
    for (int i = 0; i < nbCles; i ++)
    {
        for (int j = 0; j < nbCoffres; j ++)
        {
            for (int k = 0; k <= Cles[i]; k ++)
            {
                for (int m = 0; m < Pow[nbCoffres]; m ++)
                {
                    DP[i][j][k][m] = INFINI;
                }
            }
        }
    }
    DP[nbCles][0][0][0] = INFINI;
    int debMask = 0;
    for (int i = 0; i < nbCoffres; i ++)
    {
        debMask += Coffres[i] * Pow[i];
    }
    DP[0][0][0][debMask] = 0;
    for (int cle = 0; cle < nbCles; cle ++)
    {
        for (int coffre = 0; coffre < nbCoffres; coffre ++)
        {
            for (int pris = 0; pris <= Cles[cle]; pris ++)
            {
                for (int mask = 0; mask < Pow[nbCoffres]; mask ++)
                {
                    if (coffre + 1 == nbCoffres)
                    {
                        DP[cle + 1][0][0][mask] = min(DP[cle + 1][0][0][mask], DP[cle][coffre][pris][mask]);
                    }
                    else
                    {
                        DP[cle][coffre + 1][pris][mask] = min(DP[cle][coffre + 1][pris][mask], DP[cle][coffre][pris][mask]);
                    }
                    int libre = GetIndex(mask, coffre);
                    for (int add = 1; add <= min(libre, Cles[cle] - pris); add ++)
                    {
                        DP[cle][coffre][pris + add][mask - add * Pow[coffre]] = min(DP[cle][coffre][pris + add][mask - add * Pow[coffre]], DP[cle][coffre][pris][mask] + Verrous[coffre][cle]);
                    }
                }
            }
        }
    }
    if (DP[nbCles][0][0][0] == INFINI)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", DP[nbCles][0][0][0]);
    return;
}

signed main() {
    Read();
    Solve();
    return 0;
}