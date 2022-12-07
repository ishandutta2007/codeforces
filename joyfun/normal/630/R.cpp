#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll n;

int main() {
    scanf("%lld", &n);
    ll ans = n * n % 2;
    if (ans == 0) ans = 2;
    printf("%lld\n", ans);
    return 0;
}