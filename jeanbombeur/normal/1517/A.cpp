#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//   <|_|>

const int MAX_VALEURS = (100 * 1000);

int Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    if (nbValeurs % 2050 != 0)
    {
        printf("-1\n");
        return;
    }
    nbValeurs /= 2050;
    int ans = 0;
    while (nbValeurs > 0)
    {
        ans += nbValeurs % 10;
        nbValeurs /= 10;
    }
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}