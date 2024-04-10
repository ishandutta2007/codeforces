#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  What are you doing in my swamp ?

const int MOD = (1000 * 1000 * 1000 + 7);
const int MAX_VALEURS = (200 * 1000);

int Expo(int a, int n) {
    int ans = 1;
    int cur = a;
    for (int i = 1; i <= n; i <<= 1, cur = (cur * cur) % MOD)
    {
        if (i & n)
            ans = (ans * cur) % MOD;
    }
    return ans;
}

int nbValeurs, nbBits;

void Read() {
    scanf("%lld %lld", &nbValeurs, &nbBits);
    int ans = 0;
    if (nbValeurs & 1)
        ans = Expo(Expo(2, nbValeurs - 1) + 1, nbBits);
    else
    {
        ans = Expo(Expo(2, nbValeurs - 1) - 1, nbBits);
        for (int i = 0; i < nbBits; i ++)
        {
            ans += (Expo(Expo(2, nbValeurs - 1) - 1, nbBits - i - 1) * Expo(2, nbValeurs * i)) % MOD;
        }
    }
    printf("%lld\n", ans % MOD);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}