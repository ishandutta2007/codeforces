#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    if (n == 2) {
        cout << m << endl;
        return;
    }
    cout << m * 2 << endl;
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