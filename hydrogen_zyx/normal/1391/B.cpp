#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char g[200][200];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
                if (i == n && j == m) continue;
                if (i == n && g[i][j] == 'D') cnt++;
                if (j == m && g[i][j] == 'R') cnt++;
            }
        }
        cout << cnt << endl;
    }
}