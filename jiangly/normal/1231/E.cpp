#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    if (!is_permutation(s.begin(), s.end(), t.begin(), t.end())) {
        cout << "-1\n";
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = 0; j < n && k < n; ++j)
            if (s[j] == t[k])
                ++k;
        ans = max(ans, k - i);
    }
    cout << n - ans << "\n";
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