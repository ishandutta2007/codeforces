#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

//  Right on time

const int MAX_VALUES = (2e5);

int nbValues, Sum;

void Solve() {
    scanf("%lld %lld", &Sum, &nbValues);
    int highest = 1;
    while (highest * 10 <= Sum)
        highest *= 10;
    while (-- nbValues)
    {
        while (highest + nbValues > Sum)
            highest /= 10;
        printf("%lld ", highest);
        Sum -= highest;
    }
    printf("%lld\n", Sum);
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