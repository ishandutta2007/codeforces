#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;

//  <|_|>

//  I've been looking forward to this

const int MAX_VALUES = (2e5);

char Val[2][MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld %s %s", &nbValues, Val[0], Val[1]);
    int ans = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        if (Val[0][i] != Val[1][i])
            ans += 2;
        else
        {
            if (i + 1 < nbValues && Val[0][i + 1] == Val[1][i + 1] && Val[0][i] != Val[0][i + 1])
            {
                ans += 2;
                i ++;
            }
            else if (Val[0][i] == '0')
                ans ++;
        }
    }
    printf("%lld\n", ans);
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