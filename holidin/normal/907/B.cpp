#include <bits/stdc++.h>
using namespace std;
const int N = 5;

int main() {
    string s[N][N][N];
    int i, j, n, k, x, y, xl, yl, i1;
    //freopen("input.txt", "r", stdin);
    for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
    for (i1 = 0; i1 < 3; ++i1)
       cin >> s[i][i1][j];
    cin >> x >> y;
    xl = (x - 1) % 3;
    yl = (y - 1) % 3;
    int ans = 0;
    for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
    if (s[xl][yl][i][j] == '.') {
        ++ans;
        s[xl][yl][i][j] = '!';

    }
    if (ans == 0)
    for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
    for (i1 = 0; i1 < 3; ++i1)
    for (int j1 = 0; j1 < 3; ++j1)
    if (s[i][j][i1][j1] == '.') {
        s[i][j][i1][j1] = '!';
    }
    for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
        for (i1 = 0; i1 < 3; ++i1)
        cout << s[i][i1][j] << ' ';
        cout << endl;
    }
    cout << endl;
    }
}