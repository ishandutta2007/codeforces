// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

bool a[55][55];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        if (x <= 50 && y <= 50) {
            a[x][y] = 1;
            a[y][x] = 1;
        }
    }

    n = min(n, 50);
    for (int x=1; x<=n; x++) {
        for (int y=x+1; y<=n; y++) {
            for (int z=y+1; z<=n; z++) {
                for (int i=z+1; i<=n; i++) {
                    for (int j=i+1; j<=n; j++) {
                        int b[5] = {x, y, z, i, j};
                        int cnt = 0;
                        for (int u=0; u<5; u++) {
                            for (int v=u+1; v<5; v++) {
                                cnt += a[b[u]][b[v]];
                            }
                        }

                        if (cnt == 0 || cnt == 10) {
                            for (int x : b) cout << x << ' ';
                            cout << '\n';
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "-1\n";
}