#include <bits/stdc++.h>
using namespace std;
int g[500][500];
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (m % n) {
            cout << 2 << endl;
        } else
            cout << 0 << endl;
        memset(g, 0, sizeof(g));
        for (int i = 0; i < n && m; i++) {
            for (int j = 0; j < n && m; j++) {
                g[(i + j) % n][j % n] = 1;
                m--;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
    }
}