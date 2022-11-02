#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    int ans = 1;
    for (int i = 0; i < nbValues; i ++)
    {
        for (int j = i + 1; j < nbValues; j ++)
        {
            int cur = 0;
            for (int k = 0; k < nbValues; k ++)
            {
                cur += ((j - i) * (Val[i] - Val[k])) == ((i - k) * (Val[j] - Val[i]));
            }
            ans = max(ans, cur);
        }
    }
    printf("%lld\n", nbValues - ans);
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