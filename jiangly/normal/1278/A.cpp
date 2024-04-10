#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i + s.length() <= t.length(); ++i) {
        string h = t.substr(i, s.length());
        if (is_permutation(s.begin(), s.end(), h.begin(), h.end())) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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