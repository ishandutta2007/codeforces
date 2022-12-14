#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll A[505];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", A + i);
    ll ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) {
        ans = max(ans, A[i] | A[j] | A[k]);
    }
    printf("%lld\n", ans);
    return 0;
}