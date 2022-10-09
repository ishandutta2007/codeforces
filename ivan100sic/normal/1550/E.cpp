// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, k;
string s;
int z[200005][17];
int r[200005][17];

int d[1 << 17];

bool moze(int m) {
    memset(d, 63, sizeof(d));

    for (int i=0; i<k; i++) {
        r[n-m+1][i] = -1;
        for (int j=n-m; j>=0; j--) {
            if (z[j+m][i] - z[j][i] == m) {
                r[j][i] = j;
            } else {
                r[j][i] = r[j+1][i];
            }
        }
    }

    d[0] = 0;
    for (int mask=0; mask<(1<<k); mask++) {
        for (int i=0; i<k; i++) {
            if (!(mask & (1 << i))) {
                if (d[mask] <= n-m && r[d[mask]][i] != -1) {
                    d[mask | (1 << i)] = min(d[mask | (1 << i)], r[d[mask]][i] + m);
                }
            }
        }
    }

    return d[(1<<k)-1] <= n;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> k >> s;
    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            z[i+1][j] = z[i][j] + (s[i] == 'a' + j || s[i] == '?');
        }
    }

    int l = 1, r = n, o = 0;
    while (l <= r) {
        int m = (l+r) / 2;
        if (moze(m)) {
            o = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << o << '\n';
}