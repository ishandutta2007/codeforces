#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

const int MAX_VALUES = (1e6);

int Val[MAX_VALUES];

char Line[2][MAX_VALUES];

int nbLines, nbColumns, nbQueries;

void Solve() {
    scanf("%lld %lld", &nbLines, &nbColumns);
    int x = 0;
    scanf("%s", Line[x]);
    for (int i = 1; i < nbLines; i ++)
    {
        scanf("%s", Line[x ^ 1]);
        for (int j = 1; j < nbColumns; j ++)
        {
            if (Line[x][j] == 'X' && Line[x ^ 1][j - 1] == 'X')
                Val[j] ++;
        }
        x ^= 1;
    }
    for (int i = 1; i < nbColumns; i ++)
    {
        Val[i] += Val[i - 1];
    }
    scanf("%lld", &nbQueries);
    for (int i = 0; i < nbQueries; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        if (Val[-- b] - Val[-- a] > 0)
            printf("NO\n");
        else
            printf("YES\n");
    }
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