#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll ans = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] < a[i - 1]) ans += a[i - 1] - a[i];
        }
        cout << ans << endl;
    }
}