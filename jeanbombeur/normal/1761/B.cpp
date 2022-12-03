#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5 + 1);

int Val[MAX_VALUES];

int nbValues;

void Read() {
    scanf("%lld", &nbValues);
    int sum = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        scanf("%lld", &Val[i]);
    }
    for (int i = 0; i < nbValues; i ++)
    {
        sum += Val[(i + nbValues - 1) % nbValues] == Val[(i + nbValues + 1) % nbValues];
    }
    if (sum == nbValues)
        printf("%lld\n", nbValues / 2 + 1);
    else
        printf("%lld\n", nbValues);
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