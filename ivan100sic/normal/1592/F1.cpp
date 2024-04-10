// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
string a[505];
int b[505][505];

int ga(int i, int j) {
    if (i < n && j < m) return a[i][j] == 'B';
    return 0;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            b[i][j] = ga(i, j) ^ ga(i+1, j) ^ ga(i, j+1) ^ ga(i+1, j+1);
        }
    }

    int z = 0, f = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            z += b[i][j];
            f |= i+1 < n && j+1 < m && b[i][j] && b[n-1][j] && b[i][m-1] && b[n-1][m-1];
        }
    }

    cout << z - f << '\n';
}