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
    int sum = 0;
    int nbOdd = 0;
    int nbFix = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        if (i && i + 1 < nbValues)
        {
            sum += Val[i];
            nbOdd += Val[i] & 1;
            nbFix += 2 * (Val[i] / 2);
        }
    }
    if ((nbOdd == 1 && nbValues == 3) || (nbValues == 4 && nbOdd > nbFix))
    {
        printf("-1\n");
        return;
    }
    if (nbValues == 4)
    {
        printf("%lld\n", (sum + nbOdd) / 2);
        return;
    }
    if (nbFix == 0 && nbOdd > 0)
    {
        printf("-1\n");
        return;
    }
    printf("%lld\n", (sum + nbOdd) / 2);
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