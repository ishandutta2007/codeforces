#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5);

int Sum[MAX_VALUES];

int nbRows, nbColumns;

void Read() {
    scanf("%lld %lld", &nbRows, &nbColumns);
    for (int i = 0; i < nbRows; i ++)
    {
        Sum[i] = 0;
        for (int j = 0; j < nbColumns; j ++)
        {
            int a;
            scanf("%lld", &a);
            Sum[i] += j * a;
        }
    }
    for (int i = 0; i < nbRows; i ++)
    {
        if ((i && Sum[i] > Sum[i - 1]) || (i + 1 < nbRows && Sum[i] > Sum[i + 1]))
        {
            printf("%lld %lld\n", i + 1, Sum[i] - (i ? Sum[i - 1] : Sum[i + 1]));
        }
    }
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}