#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        --b[i];
    }
    reverse(a.begin(), a.end());
    set<int> s;
    long long ans = m;
    for (int i = 0; i < m; ++i) {
        if (s.find(b[i]) != s.end()) {
            s.erase(b[i]);
        } else {
            while (a.back() != b[i]) {
                s.insert(a.back());
                a.pop_back();
            }
            ans += 2 * s.size();
            a.pop_back();
        }
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}