#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    int ans = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
        if (i)
            ans = max(ans, Val[i] * Val[i - 1]);
    }
    printf("%lld\n", ans);
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