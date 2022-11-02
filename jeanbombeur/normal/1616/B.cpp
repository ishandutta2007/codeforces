#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//

const int MAX_VALUES = (2e5);

char Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld %s", &nbValues, Val);
    printf("%c", Val[0]);
    bool strict = false;
    for (int i = 1; i < nbValues; i ++)
    {
        if (Val[i] < Val[i - 1] || (Val[i] == Val[i - 1] && strict))
            printf("%c", Val[i]), strict = true;
        else
        {
            for (int j = i - 1; j >= 0; j --)
            {
                printf("%c", Val[j]);
            }
            break;
        }
        if (i == nbValues - 1)
        {
            for (int j = i; j >= 0; j --)
            {
                printf("%c", Val[j]);
            }
        }
    }
    if (nbValues == 1)
        printf("%c", Val[0]);
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