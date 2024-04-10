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

void Solve() {
    scanf("%lld", &nbValues);
    int nb = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    for (int i = 0; i < nbValues; i ++)
    {
        int j = i + 2;
        while (j >= 1 && Val[i] % j == 0)
            j --;
        if (j == 0)
        {
            printf("NO\n");
            return;
        }
        if (nb >= i + 1 - j)
            nb ++;
        else
        {
            printf("NO\n");
            return;
        }
    }
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