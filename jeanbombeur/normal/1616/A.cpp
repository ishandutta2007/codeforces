#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//

const int MAX_VALUES = (1e2 + 1);

int Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    fill_n(Val, MAX_VALUES, 0);
    int ans = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        int a;
        scanf("%lld", &a);
        a = abs(a);
        ans += Val[a] ++ == 0;
        if (a > 0)
            ans += Val[a] == 2;
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