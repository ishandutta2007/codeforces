#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5);

map <int, int> Last;

int nbValues;

void Read() {
    scanf("%lld", &nbValues);
    Last.clear();
    Last[0] = 1;
    int sum = 0;
    int ans = nbValues;
    for (int i = 0; i < nbValues; i ++)
    {
        int a;
        scanf("%lld", &a);
        sum ^= a;
        if (Last[sum])
        {
            ans --;
            sum = 0;
            Last.clear();
        }
        Last[sum] = 1;
    }
    printf("%lld\n", ans);
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