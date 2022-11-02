#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3;
int a[MAXN][MAXN], b[MAXN][MAXN];
vector<int> a1[MAXN], b1[MAXN];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            a1[i + j].push_back(a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
            b1[i + j].push_back(b[i][j]);
        }
    }
    bool f = true;
    for (int i = 0; i < n + m - 1 && f; ++i) {
        sort(a1[i].begin(), a1[i].end());
        sort(b1[i].begin(), b1[i].end());
        for (int j = 0; j < a1[i].size(); ++j) {
            if (a1[i][j] != b1[i][j]) {
                f = false;
                break;
            }
        }
    }
    if (f) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}