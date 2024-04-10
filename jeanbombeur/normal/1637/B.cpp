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
    for (int i = 1; i <= nbValues; i ++)
    {
        int a;
        scanf("%lld", &a);
        Val[i] = Val[i - 1] + (a == 0);
    }
    int sum = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        for (int j = i + 1; j <= nbValues; j ++)
        {
            sum += Val[j] - Val[i] + j - i;
        }
    }
    printf("%lld\n", sum);
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