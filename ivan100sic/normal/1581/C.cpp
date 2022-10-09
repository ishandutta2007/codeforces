// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int z[405][405];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto& s : a) cin >> s;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                a[i][j] %= 2;
                z[i+1][j] = a[i][j];
            }
        }

        for (int i=1; i<=n; i++) {
            for (int j=0; j<m; j++) {
                z[i][j] += z[i-1][j];
            }
        }

        int sol = 1e9;
        for (int u=0; u<n; u++) {
            for (int v=u+4; v<n; v++) {
                int offer = 1e9;
                
                for (int r=3; r<m; r++) {
                    int no1 = z[v][r-1] - z[u+1][r-1] + (2 - a[u][r-1] - a[v][r-1]);
                    int no2 = z[v][r-2] - z[u+1][r-2] + (2 - a[u][r-2] - a[v][r-2]);
                    int newoffer = no1 + no2;
                    newoffer += (v-u-1) - (z[v][r-3] - z[u+1][r-3]);
                    int wall = (v-u-1) - (z[v][r-0] - z[u+1][r-0]);
                    offer = min(newoffer, offer + no1);
                    sol = min(sol, offer + wall);
                }
            }
        }

        cout << sol << '\n';
    }
}