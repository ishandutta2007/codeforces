#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt[26] {};
    for (char c : s)
        ++cnt[c - 'a'];
    for (char c : t)
        ++cnt[c - 'a'];
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] % 2 == 1) {
            cout << "No" << "\n";
            return;
        }
    }
    cout << "Yes" << "\n";
    vector<pair<int, int>> solution;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i])
            continue;
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                solution.emplace_back(j, i);
                swap(s[j], t[i]);
                break;
            }
            if (s[i] == t[j]) {
                solution.emplace_back(j, j);
                swap(s[j], t[j]);
                solution.emplace_back(j, i);
                swap(s[j], t[i]);
                break;
            }
        }
    }
    cout << solution.size() << "\n";
    for (auto s : solution)
        cout << s.first + 1 << " " << s.second + 1 << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}