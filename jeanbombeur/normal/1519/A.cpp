#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//   <|_|>

const int MAX_VALEURS = (100 * 1000);

int Val[MAX_VALEURS];

int nbBleues, nbRouges, diff;

void Read() {
    scanf("%lld%lld%lld", &nbBleues, &nbRouges, &diff);
    if (diff * min(nbBleues, nbRouges) < abs(nbBleues - nbRouges))
        printf("NO\n");
    else
        printf("YES\n");
    return;
}

signed main() {
    int nbTests;
    scanf("%lld", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}