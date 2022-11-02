#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

// Finally

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    bool ans = true;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        if (i)
            ans &= Val[i] >= Val[i - 1];
    }
    if (ans)
        printf("NO\n");
    else
        printf("YES\n");
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