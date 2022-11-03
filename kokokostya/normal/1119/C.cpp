#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector< vector<int> > a(n, vector<int>(m));
    for (int matr = 0; matr < 2; matr++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                if (c == '1')
                    a[i][j] ^= 1;
            }
        }
    }

    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            if (a[i][j] == 1) {
                a[i][j] ^= 1;
                a[i][j + 1] ^= 1;
                a[i + 1][j] ^= 1;
                a[i + 1][j + 1] ^= 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";


    return 0;
}