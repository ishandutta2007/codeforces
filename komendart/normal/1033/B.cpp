#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
#define int long long

void solve() {
    int a, b;
    cin >> a >> b;
    if (a - b > 1) {
        cout << "NO\n";
        return;
    }
    int x = 2 * a - 1;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}