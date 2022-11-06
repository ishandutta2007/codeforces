#include <bits/stdc++.h>

using namespace std;

const int maxn = 4000;

int row[maxn];
int col[maxn];
int a[maxn][maxn];
int cnt = 0;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '*') {
                row[i]++;
                col[j]++;
                a[i][j] = 1;
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] + col[j] - a[i][j] == cnt) {
                cout << "YES\n";
                cout << i + 1 << ' ' << j + 1 << ' ' << '\n';
                return 0;
            }
        }
    }

    cout << "NO\n";
}