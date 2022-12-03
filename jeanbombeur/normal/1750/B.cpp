#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5);

char Val[MAX_VALUES];

int nbValues;

void Read() {
    scanf("%lld %s", &nbValues, Val);
    int sum = 0;
    int str = 0;
    int ans = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        sum += Val[i] == '1';
        if (i && Val[i] == Val[i - 1])
            str ++;
        else
            str = 1;
        ans = max(ans, str * str);
    }
    printf("%lld\n", max(ans, sum * (nbValues - sum)));
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