#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> psums;

int rec(string const& s, int l, int r, char c) {
    if (r - l == 1)
        return s[l] == c ? 0 : 1;

    auto& psum = psums[c - 'a'];
    int m = (l + r) / 2;

    int case1 = (m - l) - (psum[m] - psum[l]) + rec(s, m, r, c+1);
    int case2 = (r - m) - (psum[r] - psum[m]) + rec(s, l, m, c+1);
    return min(case1, case2);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    psums.assign(26, vector<int>(n+1, 0));
    for (int i = 0; i < n; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (s[i] == c)
                psums[c - 'a'][i+1] = psums[c - 'a'][i] + 1;
            else
                psums[c - 'a'][i+1] = psums[c - 'a'][i];
        }
    }

    cout << rec(s, 0, n, 'a') << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}