#include <bits/stdc++.h>
using namespace std;

#define MAXA(xi, xj, xl, yi, yj, yl, add, fr) if (dp[xi][xj][xl] < dp[yi][yj][yl] + add) { dp[xi][xj][xl] = dp[yi][yj][yl] + add; from[xi][xj][xl] = (fr);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s1, s2, virus;
    cin >> s1 >> s2 >> virus;

    vector<int> prefix;
    int border = 0;
    prefix.push_back(border);
    for (int i = 1; i < virus.size(); i++) {
        while (border > 0 && virus[border] != virus[i]) {
            border = prefix[border - 1];
        }
        if (virus[border] == virus[i])
            border++;
        prefix.push_back(border);
    }

    vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(virus.size(), 0)));

    vector<vector<vector<int>>> from(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(virus.size(), 0)));
    // 1 -> j-1
    // 2 -> i-1
    // 3 -> i-1,j-1,-3

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            for (int vlen = virus.size() - 1; vlen >= 0; vlen--) {
                MAXA(i, j, vlen, i, j-1, vlen, 0, 1);
                MAXA(i, j, vlen, i-1, j, vlen, 0, 2);
            }

            if (s1[i-1] == s2[j-1]) {
                for (int vlen = virus.size() - 1; vlen >= 0; vlen--) {
                    if (vlen > 0 && dp[i-1][j-1][vlen] == 0) continue;

                    int border = vlen;
                    while (border > 0 && s1[i-1] != virus[border]) {
                        border = prefix[border - 1];
                    }

                    if (s1[i-1] == virus[border]) {
                        border++;
                    }

                    if (border < virus.size()) {
                        MAXA(i, j, border, i-1, j-1, vlen, 1, 3 + vlen);
                    }
                }
            }
        }
    }

    int idx = 0;
    int i = s1.size();
    int j = s2.size();
    for (int vlen = 0; vlen < virus.size(); vlen++) {
        if (dp[i][j][vlen] > dp[i][j][idx])
            idx = vlen;
    }

    if (dp[i][j][idx] == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<char> res;
    while (i && j && from[i][j][idx]) {
        if (from[i][j][idx] == 1) {
            j--;
        } else if (from[i][j][idx] == 2) {
            i--;
        } else {
            res.push_back(s1[i-1]);
            idx = from[i][j][idx] - 3;
            i--;
            j--;
        }
    }

    reverse(res.begin(), res.end());
    for (char c : res) cout << c;
    cout << endl;

    return 0;
}