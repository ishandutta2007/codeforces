#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[15], Ten[15];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    Ten[0] = 1;
    for (int i = 1; i <= 10; ++i) Ten[i] = Ten[i - 1] * 10;
    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        A[0] = 0;
        for (int i = 1; i <= n; ++i) cin >> A[i];
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            ll mx = min(k + 1, Ten[A[i] - A[i - 1]] - 1);
            ans += mx * Ten[A[i - 1]];
            k -= mx;
        }
        ans += (k + 1) * Ten[A[n]];
        printf("%lld\n", ans);
    }
    return 0;
}