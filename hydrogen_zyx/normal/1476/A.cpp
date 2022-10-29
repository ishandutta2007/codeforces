#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = cos(-1.0);
const ll inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll bei = (a + b - 1) / b;
        b *= bei;
        ll ans = (b + a - 1) / a;
        cout << ans << endl;
    }
}