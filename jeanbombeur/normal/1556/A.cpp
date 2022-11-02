#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

//  <|_|>

//  Hello there

void Solve() {
    int a, b;
    scanf("%lld %lld", &a, &b);
    if (a == 0 && b == 0)
        printf("0\n");
    else if (a == b)
        printf("1\n");
    else if ((a + b) & 1)
        printf("-1\n");
    else
        printf("2\n");
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