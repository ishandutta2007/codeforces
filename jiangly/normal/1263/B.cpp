#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    set<string> s;
    int ans = 0;
    vector<string> a(n);
    vector<bool> coin(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (s.count(a[i]))
            coin[i] = true;
        s.insert(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (coin[i]) {
            ++ans;
            for (int j = 0; j < 10; ++j) {
                a[i][0] = '0' + j;
                if (!s.count(a[i]))
                    break;
            }
        }
        s.insert(a[i]);
    }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i)
        cout << a[i] << "\n";
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