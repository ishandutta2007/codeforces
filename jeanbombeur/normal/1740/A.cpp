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

int nbValues;

void Read() {
    scanf("%lld\n", &nbValues);
    if (nbValues == 2)
        printf("7\n");
    else
        printf("3\n");
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