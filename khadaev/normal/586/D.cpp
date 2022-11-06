#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input", "r", stdin);
    int t, n, k, starti, startj;
    bool cells[3][102], ok[3][102];
    cin >> t;
    for (int ii = 0; ii < t; ++ii) {
        cin >> n >> k;
        //cout << n << endl;
        char t;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < n; ++j) {
                cin >> t;
                //cout << t << " " <<  i << " "  << j << endl;
                if (t == 's') {
                    starti = i;
                    startj = j;
                    cells[i][j] = true;
                } else cells[i][j] = (t == '.');
            }
        for (int i = 0; i < 3; ++i)
            for (int j = n; j < n + 2; ++j)
                cells[i][j] = true;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < n + 2; ++j)
                ok[i][j]  = false;
        ok[starti][startj] = true;
        for (int j = 0; j < n - 1; j += 3) {
            for (int i = 0; i < 3; ++i)
                if (ok[i][j]) {
                    if (cells[i][j + 1]) {
                        ok[i][j + 1] = true;
                        if (i > 0 && cells[i - 1][j + 1]) ok[i - 1][j + 1] = true;
                        if (i < 2 && cells[i + 1][j + 1]) ok[i + 1][j + 1] = true;
                    }
                }
            for (int i = 0; i < 3; ++i)
                if (ok[i][j + 1]) {
                    if (cells[i][j + 2]) {
                        ok[i][j + 2] = true;
                        if (cells[i][j + 3]) ok[i][j + 3] = true;
                    }
                }
        }
        /*for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n + 2; ++j)
                cout << ok[i][j];
            cout << endl;
        }*/
        bool win = false;
        for (int i = 0; i < 3; ++i)
            for (int j = n - 1; j < n + 2; ++j)
                if (ok[i][j]) win = true;
        if (win) cout << "YES\n";
        else cout << "NO\n";
    }
}