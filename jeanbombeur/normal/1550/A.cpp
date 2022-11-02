#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//    <|_|>

//    We must be better than this

const int MAX_VALEURS = (200 * 1000);

int Val[MAX_VALEURS];

int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    int sum = 1;
    int cur = 1;
    while (sum < nbValeurs)
    {
        cur += 2;
        sum += cur;
    }
    printf("%lld\n", (cur + 1) / 2);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}