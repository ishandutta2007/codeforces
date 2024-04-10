#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbNodes, nbRestrictions;

void Solve() {
    scanf("%lld %lld", &nbNodes, &nbRestrictions);
    // fill_n(Val, Val + nbNodes, 0);
    for (int i = 0; i < nbNodes; i ++)
    {
        Val[i] = 0;
    }
    for (int i = 0; i < nbRestrictions; i ++)
    {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        Val[-- b] ++;
    }
    for (int i = 0; i < nbNodes; i ++)
    {
        if (Val[i] == 0)
        {
            for (int j = 0; j < nbNodes; j ++)
            {
                if (i ^ j)
                    printf("%lld %lld\n", i + 1, j + 1);
            }
            return;
        }
    }
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