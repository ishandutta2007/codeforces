#include<bits/stdc++.h>

using namespace std;

string dp[256][3];
int was[256][3], c;

string f(string a, string b) {
    if ((int) a.size() == 0) {
        return b;
    }
    if ((int) b.size() == 0) {
        return a;
    }
    if ((int) a.size() > (int) b.size()) {
        return b;
    }
    if ((int) b.size() > (int) a.size()) {
        return a;
    }
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

void upd(string s, int msk, int j) {
    string lst = dp[msk][j];
    dp[msk][j] = f(dp[msk][j], s);
    if (dp[msk][j] != lst) {
        was[msk][j] = c;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[0][0] = "";
    dp[(1 << 4) + (1 << 5) + (1 << 6) + (1 << 7)][0] = "x";
    dp[(1 << 2) + (1 << 3) + (1 << 6) + (1 << 7)][0] = "y";
    dp[(1 << 1) + (1 << 3) + (1 << 5) + (1 << 7)][0] = "z";
    for (c = 1; c < 100; c++) {
        for (int msk = 0; msk < 256; msk++) for (int x = 0; x < 3; x++) {
            if ((int) dp[msk][x].size() == 0) {
                continue;
            }
            upd((string) "!" + (x ? "(" : "") + dp[msk][x] + (x ? ")" : ""), 255 - msk, 0);
            for (int msk2 = 0; msk2 < 256; msk2++) for (int y = 0; y < 3; y++) {
                if ((int) dp[msk2][y].size() == 0) {
                    continue;
                }
                if (was[msk][x] < c - 1 && was[msk2][y] < c - 1) {
                    continue;
                }
                upd((x == 2 ? "(" : "") + dp[msk][x] + (x == 2 ? ")" : "") + "&" + (y ? "(" : "") + dp[msk2][y] + (y ? ")" : ""), msk & msk2, 1);
                upd(dp[msk][x] + "|" + (y == 2 ? "(" : "") + dp[msk2][y] + (y == 2 ? ")" : ""), msk | msk2, 2);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int msk = 0;
        for (int j = 0; j < 8; j++) {
            if (s[j] == '1') {
                msk += (1 << j);
            }
        }
        cout << f(dp[msk][0], f(dp[msk][1], dp[msk][2])) << '\n';
    }
}