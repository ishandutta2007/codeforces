#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  The hardest choices require the strongest wills
//  We must be better

const int MAX_VALEURS = (200 * 1000);
const int NB = (5);

int Val[MAX_VALEURS][NB];

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        for (int j = 0; j < NB; j ++)
        {
            scanf("%lld", &Val[i][j]);
        }
    }
    int curMax = 0;
    for (int i = 1; i < nbValeurs; i ++)
    {
        int nb = 0;
        for (int j = 0; j < NB; j ++)
        {
            nb += Val[curMax][j] > Val[i][j];
        }
        if (nb >= 3)
            curMax = i;
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        int nb = 0;
        for (int j = 0; j < NB; j ++)
        {
            nb += Val[curMax][j] > Val[i][j];
        }
        if (nb >= 3)
        {
            printf("-1\n");
            return;
        }
    }
    printf("%lld\n", ++ curMax);
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