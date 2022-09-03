#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }
    vector<vector<int>> qs(q);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1 || t == 2) {
            int x;
            cin >> x;
            qs[i].push_back(t);
            qs[i].push_back(x);
        } else {
            int r, c, x;
            cin >> r >> c >> x;
//            qs.push_back({t, r, c, x});
            qs[i].push_back(t);
            qs[i].push_back(r);
            qs[i].push_back(c);
            qs[i].push_back(x);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        int t = qs[i][0];
        if (t == 1) {
            int r = qs[i][1];
            r--;
            int l = a[r][m - 1];
            for (int j = m - 1; j > 0; j--) {
                a[r][j] = a[r][j - 1];
            }
            a[r][0] = l;
        } else if (t == 2) {
            int c = qs[i][1];
            c--;
            int l = a[n - 1][c];
            for (int j = n - 1; j > 0; j--) {
                a[j][c] = a[j - 1][c];
            }
            a[0][c] = l;
        } else {
            int r = qs[i][1], c = qs[i][2], x = qs[i][3];
            r--;
            c--;
            a[r][c] = x;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}