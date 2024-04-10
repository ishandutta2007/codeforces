#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//   <|_|>

const int INFINI = (100 * 1000 * 1000);
const int MAX_VALEURS = (5000);

int DP[2][2 * MAX_VALEURS];

int Occupe[MAX_VALEURS];

int nbFauteuils;

void Init() {
    for (int i = 0; i < 2; i ++)
    {
        for (int j = 0; j < 2 * MAX_VALEURS; j ++)
        {
            DP[i][j] = INFINI;
        }
    }
    return;
}

void Read() {
    scanf("%d", &nbFauteuils);
    for (int i = 0; i < nbFauteuils; i ++)
    {
        scanf("%d", &Occupe[i]);
    }
    if (Occupe[0])
        DP[0][nbFauteuils - 1] = 0;
    else
    {
        DP[0][nbFauteuils + 1] = 0;
        DP[0][nbFauteuils] = 0;
    }
    int cur = 1;
    for (int i = 1; i < nbFauteuils; i ++)
    {
        if (Occupe[i])
        {
            for (int d = 0; d < 2 * nbFauteuils - 1; d ++)
            {
                DP[cur][d] = DP[cur ^ 1][d + 1] + abs(d + 1 - nbFauteuils);
            }
        }
        else
        {
            for (int d = 1; d < 2 * nbFauteuils; d ++)
            {
                DP[cur][d] = DP[cur ^ 1][d - 1] + abs(d - 1 - nbFauteuils);
                DP[cur][d] = min(DP[cur][d], DP[cur ^ 1][d] + abs(d - nbFauteuils));
            }
        }
        cur ^= 1;
    }
    printf("%d\n", DP[cur ^ 1][nbFauteuils]);
    return;
}

int main() {
    Init();
    Read();
    return 0;
}