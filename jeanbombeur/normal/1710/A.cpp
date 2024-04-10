#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5);

int Val[MAX_VALUES];

int nbLines, nbColumns, nbColors;

void Read() {
    scanf("%lld %lld %lld", &nbLines, &nbColumns, &nbColors);
    int sum1 = 0;
    int sum2 = 0;
    bool greater1 = false;
    bool greater2 = false;
    for (int i = 0; i < nbColors; i ++)
    {
        scanf("%lld", &Val[i]);
        if (Val[i] / nbLines >= 2)
            sum1 += Val[i] / nbLines;
        if (Val[i] / nbColumns >= 2)
            sum2 += Val[i] / nbColumns;
        if (Val[i] / nbLines >= 3)
            greater1 = true;
        if (Val[i] / nbColumns >= 3)
            greater2 = true;
    }
    if (sum1 >= nbColumns && (greater1 || (!(nbColumns & 1))))
        printf("Yes\n");
    else if (sum2 >= nbLines && (greater2 || (!(nbLines & 1))))
        printf("Yes\n");
    else
        printf("No\n");
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