#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200000];
map<ll, ll> m;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n + 1; i++) cin >> a[i];
    partial_sum(a + 2, a + 2 + n, a + 2);
    n++;
    ll p1 = 1, p2 = 1, k, ans = 0;
    for (;;) {
        while (p2 <= n && m[a[p2]] < p1) {
            m[a[p2]] = p2;
            p2++;
        }
        if (p2 == n + 1) {
            ans += (n - p1) * (n - p1 + 1) / 2;
            break;
        }
        k = m[a[p2]];
        ans += (k - p1 + 1) * (2 * p2 - p1 - k - 2) / 2;
        p1 = k + 1;
    }
    cout << ans;
}