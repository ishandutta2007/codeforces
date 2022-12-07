#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef unsigned long long ll;

ll n;

int main() {
    scanf("%llu", &n);
    ll ans = 1;
    for (int i = 0; i < 5; i++) {
        ans = ans * (n - i) / (i + 1) * (n - i);
    }
    printf("%llu\n", ans);
    return 0;
}