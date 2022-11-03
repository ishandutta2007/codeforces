#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    sort(s.rbegin(), s.rend());
    vector<string> ans(n, string(l, '.'));
    int start = 0;
    for (int i = 0; i < l; ++i) {
        int new_start = start;
        for (int j = start; j < k; ++j) {
            ans[j][i] = s.back();
            s.pop_back();
            if (j > start && ans[j][i] != ans[j - 1][i]) {
                new_start = j;
            }
        }
        start = new_start;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            if (ans[i][j] == '.') {
                ans[i][j] = s.back();
                s.pop_back();
            }
        }
    }
    for (const string& t: ans) {
        cout << t << "\n";
    }
}