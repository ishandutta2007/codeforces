#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), c(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) p[i]--;
    vector<bool> used(n, false);
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        vector<int> a;
        int j = i;
        while (true) {
            a.push_back(j);
            used[j] = true;
            j = p[j];
            if (j == i) break;
        }
        int x = a.size();
        for (int i = 1; i <= x; i++) {
            if (x % i != 0) continue;
            for (int j = 0; j < i; j++) {
                bool f = true;
                for (int k = 0; j + k * i < x; k++) {
                    if (c[a[j]] != c[a[j + k * i]]) f = false;
                }
                if (f) ans = min(ans, i);
            }
        }
    }
    cout << ans << endl;
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