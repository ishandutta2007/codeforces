#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    bool f = false, f2 = false;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && (s[i] - '0') % 2 == 1) f = true;
        else if (i % 2 == 1 && (s[i] - '0') % 2 == 0) f2 = true;
    }
    if (n % 2 == 1) {
        if (f) cout << "1\n";
        else cout << "2\n";
    }
    else {
        if (f2) cout << "2\n";
        else cout << "1\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) solve();
}