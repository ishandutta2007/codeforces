// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> e(1 << n);
        for (int i=0; i<(n<<n)/2; i++) {
            int x, y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        vector<int> q(1 << n);
        string vis(1 << n, 0);
        vis[0] = 1;
        int qs = 0, qe = 1;

        while (qs != qe) {
            int x = q[qs++];
            for (int y : e[x]) {
                if (!vis[y]) {
                    vis[y] = 1;
                    q[qe++] = y;
                }
            }
        }

        vector<int> p(1 << n, -1);
        p[q[0]] = 0;
        for (int i=1; i<=n; i++) {
            p[q[i]] = 1 << (i - 1);
        }

        for (int i=n+1; i<(1<<n); i++) {
            vector<int> c(n, 0);
            for (int j : e[q[i]]) {
                if (p[j] != -1) {
                    for (int k=0; k<n; k++) {
                        if (p[j] & (1 << k)) {
                            c[k]++;
                        }
                    }
                }
            }
            int v = 0;
            for (int j=0; j<n; j++) {
                if (c[j]) {
                    v |= 1 << j;
                }
            }
            p[q[i]] = v;
        }

        vector<int> pinv(1 << n);
        for (int i=0; i<(1<<n); i++) {
            pinv[p[i]] = i;
        }

        for (int i=0; i<(1<<n); i++) {
            cout << pinv[i] << " \n"[i == (1<<n) - 1];
        }

        if (n == 1 || n == 2 || n == 4 || n == 8 || n == 16) {
            for (int i=0; i<(1<<n); i++) {
                int v = 0;
                for (int j=0; j<n; j++) {
                    if (p[i] & (1 << j)) {
                        v ^= j;
                    }
                }
                cout << v << " \n"[i == (1<<n) - 1];
            }
        } else {
            cout << "-1\n";
        }
    }
}