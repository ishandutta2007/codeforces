#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MOD = (998244353);
const int MAX_BITS = (2e5 + 1);
const int NB_MASK = 8;

int DP[MAX_BITS][NB_MASK][NB_MASK];

char Bits[MAX_BITS];
int Val[MAX_BITS];

int nbBits;

int Expo(int a, int n) {
    int ans = 1, cur = a;
    for (; n; n >>= 1)
    {
        if (n & 1)
            ans = (ans * cur) % MOD;
        cur = (cur * cur) % MOD;
    }
    return ans;
}

void Read() {
    scanf("%s", Bits);
    nbBits = strlen(Bits);
    for (int i = 0; i < NB_MASK; i ++)
    {
        DP[0][7][i] = 1;
    }
    reverse(Bits, Bits + nbBits);
    for (int i = 1; i <= nbBits; i ++)
    {
        Val[i] = Bits[i - 1] - '0';
    }
    for (int bits = 1; bits <= nbBits; bits ++)
    {
        for (int cons = 0; cons < NB_MASK; cons ++)
        {
            for (int equal = 0; equal < NB_MASK; equal ++)
            {
                for (int mask = 0; mask < NB_MASK; mask ++)
                {
                    int nvCons = cons;
                    int nvEqual = equal;
                    int ok = 1;
                    for (int i = 0; i < 3; i ++)
                    {
                        int bit = (mask >> i) & 1;
                        if (((equal >> i) & 1) && bit > Val[bits])
                            ok = 0;
                        if (bit != Val[bits])
                            nvEqual &= (7 ^ (1 << i));
                        if (mask == (1 << i) || mask == (7 ^ (1 << i)))
                            nvCons |= (1 << i);
                    }
                    if (ok)
                        DP[bits][cons][equal] += DP[bits - 1][nvCons][nvEqual];
                }
                DP[bits][cons][equal] %= MOD;
            }
        }
    }
    printf("%lld\n", DP[nbBits][0][7]);
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}