#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll n;

ll C(int n, int m) {
    if (m > n || n < 0 || m < 0) return 0;
    m = min(m, n - m);
    ll ans = 1;
    for (int i = 0; i < m; i++)
        ans = ans * (n - i) / (i + 1);
    return ans;
}

int main() {
    scanf("%lld", &n);
    printf("%lld\n", C(n + 4, n - 1) * C(n + 2, n - 1));
    return 0;
}