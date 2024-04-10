#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, d;
        cin >> n >> d;
        ll ans = d;
        for (ll i = 1; i <= 1e5; ++i) {
            ans = min(ans, i + (d + i) / (i + 1));
        }
        cout << (ans <= n ? "YES\n" : "NO\n");
    }
}