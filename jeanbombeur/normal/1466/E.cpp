#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//     <|_|>

const int MOD = (1000 * 1000 * 1000 + 7);
const int MAX_VALEURS = (500 * 1000);
const int MAX_BITS = 60;

int Val[MAX_VALEURS];

int Nb[MAX_BITS];

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    for (int i = 0; i < MAX_BITS; i ++)
    {
        Nb[i] = 0;
    }
    for (int i = 0; i < nbValeurs; i ++)
    {
        scanf("%lld", &Val[i]);
        for (int j = 0; j < MAX_BITS; j ++)
        {
            if (Val[i] & (1LL << j))
            {
                Nb[j] ++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < nbValeurs; i ++)
    {
        int andSum = 0;
        int orSum = 0;
        for (int j = 0; j < MAX_BITS; j ++)
        {
            int curBit = (1LL << j);
            int valCalcule = curBit % MOD;
            if (curBit & Val[i])
            {
                andSum += valCalcule * Nb[j];
                andSum %= MOD;
                orSum += valCalcule * nbValeurs;
                orSum %= MOD;
            }
            else
            {
                orSum += valCalcule * Nb[j];
                orSum %= MOD;
            }
        }
        ans += andSum * orSum;
        ans %= MOD;
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