#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1005;

int t, n, k;
char c[MAXN][MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> c[i][j];
            }
        }
        bool ima = 0;
        int a = 1, b = 2;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (c[i][j] == c[j][i]) {
                    ima = 1;
                    a = i; b = j;
                }
            }
        }
        if (k % 2 == 1 || ima) {
            cout << "YES\n";
            for (int i = 0; i < k + 1; i++) cout << (i % 2 ? a : b) << " ";
            cout << '\n';
        } else if (n == 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int x, y, z;
            if (c[1][2] == c[2][3]) x = 1, y = 2, z = 3;
            if (c[2][3] == c[3][1]) x = 2, y = 3, z = 1;
            if (c[3][1] == c[1][2]) x = 3, y = 1, z = 2;
            if (k % 4 == 2) {
                cout << x << " ";
                for (int i = 0; i < k; i++) {
                    if (i % 4 == 0) cout << y << " ";
                    if (i % 4 == 1) cout << z << " ";
                    if (i % 4 == 2) cout << y << " ";
                    if (i % 4 == 3) cout << x << " ";
                }
            } else {
                cout << y << " ";
                for (int i = 0; i < k; i++) {
                    if (i % 4 == 0) cout << z << " ";
                    if (i % 4 == 1) cout << y << " ";
                    if (i % 4 == 2) cout << x << " ";
                    if (i % 4 == 3) cout << y << " ";
                }
            }
            cout << '\n';
        }
    }
    return 0;
}