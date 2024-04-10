#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> k;
        ll ans = 1 << k;
        for (ll i = 1; i < k / 2; i++) {
            ans += 1 << i;
        }
        for (ll i = k / 2; i < k; i++) {
            ans -= 1 << i;
        }
        cout << ans << endl;
    }
}