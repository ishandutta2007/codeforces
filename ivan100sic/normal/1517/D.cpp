// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m, k;
int h[505][505], v[505][505];

int a[2][25][25];

void mn(int& x, int y) {
    x = min(x, y);
}

int solve(int x, int y) {
    
    auto get = [&](auto b, int i, int j) -> int& {
        return b[i-x+12][j-y+12];
    };

    memset(a, 63, sizeof(a));
    get(a[0], x, y) = 0;

    for (int s=0; s<k; s++) {
        auto ol = a[s % 2];
        auto nu = a[1 - s % 2];
        memset(nu, 63, sizeof(a[0]));
        for (int r=-s; r<=s; r++) {
            int d = s - abs(r);
            for (int c=-d; c<=d; c+=2) {
                int i = x + r;
                int j = y + c;
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                int val = get(ol, i, j);
                if (i > 0) mn(get(nu, i-1, j), val + v[i-1][j]);
                if (i < n - 1) mn(get(nu, i+1, j), val + v[i][j]);
                if (j > 0) mn(get(nu, i, j-1), val + h[i][j-1]);
                if (j < m - 1) mn(get(nu, i, j+1), val + h[i][j]);
            }
        }
    }

    int z = 1e9;

    for (int i=0; i<25; i++) {
        for (int j=0; j<25; j++) {
            z = min(z, a[k%2][i][j]);
        }
    }

    return 2 * z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m-1; j++) {
            cin >> h[i][j];
        }
    }

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    
    if (k % 2) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << -1 << " \n"[j == m-1];
            }
        }
        return 0;
    }

    k /= 2;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << solve(i, j) << " \n"[j == m-1];
        }
    }
}