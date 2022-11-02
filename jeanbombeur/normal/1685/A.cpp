#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  We must be better

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    sort(Val, Val + nbValues);
    if (nbValues & 1)
    {
        printf("NO\n");
        return;
    }
    int mid = nbValues / 2;
    for (int i = 1; i < mid; i ++)
    {
        if (Val[i] == Val[i + mid - 1])
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    for (int i = 0; i < mid; i ++)
    {
        printf("%lld %lld ", Val[i], Val[i + mid]);
    }
    printf("\n");
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