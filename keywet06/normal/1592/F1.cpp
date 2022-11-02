#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> s(n + 1, vector<char>(m + 1, 'W'));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> s[i][j];
    }
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int Cnt = 0;
            if (s[i][j] == 'B') ++Cnt;
            if (i < n) {
                if (s[i + 1][j] == 'B') ++Cnt;
            }
            if (j < m) {
                if (s[i][j + 1] == 'B') ++Cnt;
            }
            if (i < n && j < m) {
                if (s[i + 1][j + 1] == 'B') ++Cnt;
            }
            a[i][j] = Cnt % 2;
        }
    }
    int Cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 1) ++Cnt;
        }
    }
    int Ans = Cnt;
    if (a[n][m] == 1) {
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (a[i][j] == 1 && a[i][m] == 1 && a[n][j] == 1) {
                    Ans = Cnt - 1;
                }
            }
        }
    }
    cout << Ans << endl;
    return 0;
}