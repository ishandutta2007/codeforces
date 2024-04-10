#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[4][4];
    a[0][0] = 8;
    a[0][1] = 9;
    a[0][2] = 1;
    a[0][3] = 13;
    a[1][0] = 3;
    a[1][1] = 12;
    a[1][2] = 7;
    a[1][3] = 5;
    a[2][0] = 0;
    a[2][1] = 2;
    a[2][2] = 4;
    a[2][3] = 11;
    a[3][0] = 6;
    a[3][1] = 10;
    a[3][2] = 15;
    a[3][3] = 14;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int ii = i / 4, jj = j / 4;
            tmp = a[i % 4][j % 4];
            cout << tmp + 16 * jj + 4 * n * ii << " ";
        }
        cout << endl;
    }
}