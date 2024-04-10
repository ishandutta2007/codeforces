#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  I've been looking forward to this

//  <|_|>

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbValues;

void Solve() {
    scanf("%lld", &nbValues);
    int zero = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
        zero += Val[i] == 0;
    }
    int deb = 0, fin = nbValues;
    while (deb < fin && Val[deb] == 0)
        deb ++;
    while (fin > deb && Val[fin - 1] == 0)
        fin --;
    if (zero == nbValues)
    {
        printf("0\n");
        return;
    }
    for (int i = deb; i < fin; i ++)
    {
        if (Val[i] == 0)
        {
            printf("2\n");
            return;
        }
    }
    printf("1\n");
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