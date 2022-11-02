#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  I've been looking forward to this

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    int ans = 0;
    
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        ans += Val[i];
    }
    
    
    printf("%d\n", (ans % nbValues) > 0);
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