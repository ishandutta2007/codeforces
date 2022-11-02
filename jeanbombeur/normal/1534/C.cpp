#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//    <|_|>

//   The hardest choices require the strongest wills

const int MOD = (1000 * 1000 * 1000 + 7);
const int MAX_VALEURS = (400 * 1000 + 2);

int Val[MAX_VALEURS];
int Next[MAX_VALEURS];

bool Vu[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    for (int i = 0; i < nbValeurs; i ++)
    {
        Vu[i] = false;
        scanf("%lld", &Val[i]);
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        int a;
        scanf("%lld", &a);
        Next[-- Val[i]] = -- a;
    }
    int ans = 1;
    for (int i = 0; i < nbValeurs; i ++)
    {
        if (!Vu[i])
        {
            Vu[i] = true;
            ans *= 2;
            ans %= MOD;
            for (int j = Next[i]; j != i; j = Next[j])
            {
                Vu[j] = true;
            }
        }
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