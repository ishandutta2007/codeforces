#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I'm Batman

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

int nbValeurs;

void Solve() {
    scanf("%lld", &nbValeurs);
    bool t = false;
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
        if (i && !Val[i - 1] && Val[i])
            t = true;
    }
    Val[nbValeurs] = 1;
    if (!Val[nbValeurs - 1])
        t = true;
    if (Val[0])
        t = true;
    if (!t)
    {
        printf("-1\n");
        return;
    }
    if (Val[0])
    {
        printf("%lld ", nbValeurs + 1);
        t = false;
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        printf("%lld ", i + 1);
        if (t && !Val[i] && Val[i + 1])
        {
            printf("%lld ", nbValeurs + 1);
            t = false;
        }
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}