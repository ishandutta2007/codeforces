#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues;

bool IsPrime(int n) {
    for (int d = 2; d * d <= n; d ++)
    {
        if (n % d == 0)
            return false;
    }
    return true;
}

void Solve() {
    scanf("%lld", &nbValues);
    int sum = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        sum += Val[i];
    }
    if (!IsPrime(sum))
    {
        printf("%lld\n", nbValues);
        for (int i = 0; i < nbValues; i ++)
        {
            printf("%lld ", i + 1);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < nbValues; i ++)
    {
        if (!IsPrime(sum - Val[i]))
        {
            printf("%lld\n", nbValues - 1);
            for (int j = 0; j < nbValues; j ++)
            {
                if (j ^ i)
                    printf("%lld ", j + 1);
            }
            printf("\n");
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