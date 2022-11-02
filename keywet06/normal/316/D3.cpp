#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;
const int N = 1200005;

int g[N];

int main() {
    int n;
    scanf("%d", &n);
    int k1 = 0, k2 = 0;
    for (int i = 0; i < n; ++i) {
        int foo;
        scanf("%d", &foo);
        ++(foo == 1 ? k1 : k2);
    }
    g[0] = 1;
    for (int i = 1; i <= k1; ++i) {
        g[i] = (g[i - 1] + (long long)g[i - 2] * (i - 1)) % P;
    }
    int ans = g[k1];
    for (int i = 1; i <= k2; ++i) ans = (long long)ans * (k1 + i) % P;
    printf("%d\n", ans);
    return 0;
}