#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        for (ll bt = 1; bt <= 1e9; bt *= 10) {
            if (bt * 10 - 1 <= b) {
                ans += a;
            }
        }
        cout << ans << '\n';
    }
}