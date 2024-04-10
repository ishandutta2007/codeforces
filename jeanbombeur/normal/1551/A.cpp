#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Ah shit, here we go again

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

int nbValeurs;

void Solve() {
    scanf("%lld", &nbValeurs);
    int mid = nbValeurs / 3;
    printf("%lld %lld\n", mid + (nbValeurs % 3 == 1), mid + (nbValeurs % 3 == 2));
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