#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, A[200005];
int main() {
    scanf("%d", &n);
    int cnt[25] = {};
    for (int i = 1; i <= n; i++) {
        scanf("%d", A + i);
        for (int j = 0; j < 20; j++) {
            cnt[j] += ((A[i] >> j) & 1);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll x = 0;
        for (int j = 0; j < 20; j++) {
            if (i <= cnt[j]) x += (1 << j);
        }
        ans += x * x;
    }
    printf("%lld\n", ans);
}