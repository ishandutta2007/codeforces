#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I'm back !

const int MAX_VALUES = (1 << 20);

int Val[MAX_VALUES];

int Last[MAX_VALUES];
int Nb[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    nbValues ++;
    for (int i = 1; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    int maximum = 0;
    for (int bit = 19; bit >= 0; bit --)
    {
        fill_n(Last, (1 << (20 - bit)), -1);
        int mask = 0;
        Last[0] = 0;
        Nb[0] = 0;
        for (int i = 1; i < nbValues; i ++)
        {
            Nb[i] = Nb[i - 1] + ((Val[i] >> bit) & 1);
            mask ^= Val[i] >> bit;
            if (Last[mask] >= 0)
            {
                if (Nb[i] - Nb[Last[mask]] == i - Last[mask])
                    maximum = max(maximum, i - Last[mask]);
                else
                    Last[mask] = i;
            }
            else
                Last[mask] = i;
        }
    }
    printf("%lld\n", maximum);
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}