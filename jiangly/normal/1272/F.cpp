#include <bits/stdc++.h>
using namespace std;
void cmax(int &a, int b) {
    if (a < b)
        a = b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    vector<int> dp[801][401];
    for (auto &i : dp)
        for (auto &j : i)
            j.assign(s.length() + 1, -1);
    dp[0][0][0] = 0;
    for (int i = 0; i < 800; ++i) {
        for (int j = 0; j < 400; ++j) {
            for (int k = 0; k <= s.length(); ++k) {
                if (dp[i][j][k] == -1)
                    continue;
                for (char c : {'(', ')'}) {
                    int v = c == '(' ? 1 : -1;
                    if (0 <= j + v && j + v <= 400)
                        cmax(dp[i + 1][j + v][k == s.length() ? k : k + (c == s[k])], dp[i][j][k] == t.length() ? dp[i][j][k] : dp[i][j][k] + (t[dp[i][j][k]] == c));
                }
            }
        }
    }
    int ans = 0;
    while (dp[ans][0][s.length()] != t.length())
        ++ans;
    string f;
    int x = 0, y = s.length();
    for (int i = ans; i >= 1; --i) {
        int val = dp[i][x][y];
        [&]{
            for (char c : {'(', ')'}) {
                int v = c == '(' ? 1 : -1;
                if (x - v < 0 || x - v > 400)
                    continue;
                for (int k = max(0, y - 1); k <= y; ++k) {
                    int l = dp[i - 1][x - v][k];
                    if (l != -1 && y == (k == s.length() ? k : k + (c == s[k])) && val == (l == t.length() ? l : l + (c == t[l]))) {
                        f += c;
                        x -= v;
                        y = k;
                        return;
                    }
                }
            }
        }();
    }
    reverse(f.begin(), f.end());
    cout << f << endl;
    return 0;
}