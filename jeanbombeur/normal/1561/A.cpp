#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  It that's what it takes to save the world, it's better to let that world die

const int MAX_CASES = (1e3);

int Perm[MAX_CASES];

int nbCases;

void Solve() {
    scanf("%lld", &nbCases);
    for (int i = 0; i < nbCases; i ++)
    {
        scanf("%lld", &Perm[i]);
    }
    Perm[nbCases] = nbCases;
    for (int k = 0; k <= nbCases; k ++)
    {
        bool end = true;
        for (int i = k & 1; i < nbCases; i += 2)
        {
            if (Perm[i + 1] < Perm[i])
                swap(Perm[i], Perm[i + 1]), end = false;
            if (i && Perm[i] < Perm[i - 1])
                end = false;
        }
        if (end)
        {
            printf("%lld\n", k);
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