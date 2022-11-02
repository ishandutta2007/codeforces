#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
string arr[MAXN];

int n, m;

int check(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && arr[i][j] == '1';
}

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        bool f = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] == '1') continue;
                for (int p = -1; p <= 1; p += 2) {
                    for (int q = -1; q <= 1; q += 2) {
                        if (check(i + p, j + q) && check(i, j + q) && check(i + p, j)) f = true;
                    }
                }
            }
        }
        if (f) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}