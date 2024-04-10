#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
// #define int long long
using namespace std;

//  <|_|>

const int MAX_VALUES = (3e5);

int nbNodes, sizePath;

void Solve() {
    scanf("%d %d", &nbNodes, &sizePath);
    int nbColors = 1;
    int nb = sizePath;
    while (nb < nbNodes)
        nb *= sizePath, nbColors ++;
    printf("%d\n", nbColors);
    for (int i = 0; i < nbNodes; i ++)
    {
        int color = 1;
        int jump = sizePath;
        for (int j = i + 1; j < nbNodes; j ++)
        {
            while (j % jump == 0)
                color ++, jump *= sizePath;
            printf("%d ", color);
        }
    }
    printf("\n");
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}