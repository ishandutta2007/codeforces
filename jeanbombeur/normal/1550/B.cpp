#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//    <|_|>

//    We must be better than this

const int MAX_VALEURS = (200 * 1000);

char Val[MAX_VALEURS];

int nbValeurs, a, b;

void Read() {
    scanf("%lld %lld %lld", &nbValeurs, &a, &b);
    int nbGroupes = 1;
    scanf("%s", Val);
    for (int i = 1; i < nbValeurs; i ++)
    {
        if (Val[i] != Val[i - 1])
            nbGroupes ++;
    }
    if (b >= 0)
        printf("%lld\n", (a + b) * nbValeurs);
    else
        printf("%lld\n", a * nbValeurs + b * ((nbGroupes + 2) / 2));
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