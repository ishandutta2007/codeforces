#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    long long ans = 0;
    for (int t = 0; t < 2; t++) {
        multiset<int> c[2];
        for (int i = 0; i < n; i++) {
            c[a[i]].insert(b[i]);
        }
        long long res = 0, g = -1;
        for (int y = 0; y < 2 * n; y++) {
            int j = (y + t) % 2;
            if ((int) c[j].size()) {
                int x = *c[j].rbegin();
                if (g == -1) {
                    x = *c[j].begin();
                }
                c[j].erase(c[j].find(x));
                if (g != -1 && g != j) {
                    res += 2 * x;
                } else {
                    res += x;
                }
                g = j;
            }
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}