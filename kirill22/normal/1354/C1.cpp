#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double
#define all(a) a.begin(), a.end()

void solve() {
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    if (n % 2 == 0) {
       ld a = (360.0 / n) / 4.0;
       ld g = 0.5 / (sin((a * 3.1415926) / 180.0));
       cout << sqrt(g * g - 0.5 * 0.5) * 2.0 << endl;
    }
    else {
       ld a = (360.0 / n) / 4.0;
       ld g = 0.5 / (sin((a * 3.1415926) / 180.0));
       cout << g * 2.0 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}