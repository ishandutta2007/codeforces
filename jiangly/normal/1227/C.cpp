
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<pair<int, int>> sol;
    for (int i = 0; i < k - 1; ++i) {
        for (int j = 2 * i; ; ++j) {
            if (s[j] == '(') {
                reverse(s.begin() + 2 * i, s.begin() + j + 1);
                sol.emplace_back(2 * i, j);
                break;
            }
        }
        for (int j = 2 * i + 1; ; ++j) {
            if (s[j] == ')') {
                reverse(s.begin() + 2 * i + 1, s.begin() + j + 1);
                sol.emplace_back(2 * i + 1, j);
                break;
            }
        }
    }
    for (int i = 2 * (k - 1); i < n / 2 + k - 1; ++i) {
        for (int j = i; ; ++j) {
            if (s[j] == '(') {
                reverse(s.begin() + i, s.begin() + j + 1);
                sol.emplace_back(i, j);
                break;
            }
        }
    }
    cout << sol.size() << "\n";
    for (auto p : sol)
        cout << p.first + 1 << " " << p.second + 1 << "\n";
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