#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        char a[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        for (int j = 0; j < m; j++) {
            int pos = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (a[i][j] == 'o') {
                    pos = i - 1;
                } else if (a[i][j] == '*') {
                    while (pos > i && a[pos][j] != '.') {
                        pos--;
                    }
                    if (pos > i) {
                        swap(a[i][j], a[pos][j]);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
}