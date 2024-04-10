#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

const int MAX_VALUES = (1e6 + 1);

int Occ[MAX_VALUES];

int nbValues, maximum;

void Solve() {
    scanf("%lld %lld", &nbValues, &maximum);
    maximum ++;
    fill_n(Occ, maximum, false);
    for (int i = 0; i < nbValues; i ++)
    {
        int a;
        scanf("%lld", &a);
        Occ[a] = 1;
    }
    for (int i = 1; i < maximum; i ++)
    {
        Occ[i] += Occ[i - 1];
    }
    for (int i = 1; i < maximum; i ++)
    {
        if (Occ[i] ^ Occ[i - 1])
        {
            for (int j = 1; j * i < maximum; j ++)
            {
                if (Occ[min(j * i + i - 1, maximum - 1)] ^ Occ[j * i - 1] && !(Occ[j] ^ Occ[j - 1]))
                {
                    printf("No\n");
                    return;
                }
            }
        }
    }
    printf("Yes\n");
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