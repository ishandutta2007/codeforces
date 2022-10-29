#include <bits/stdc++.h>
using namespace std;
char g[200][200];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ((i + j) & 1)
                    g[i][j] = 'W';
                else
                    g[i][j] = 'B';
            }
        }
        if (n % 2 == 0 && m % 2 == 0)
            g[n][m - 1] = 'B';
        else if (n % 2 == 0 || m % 2 == 0)
            g[n][m] = 'B';
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
    }
}