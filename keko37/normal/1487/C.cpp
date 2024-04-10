#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 105;

int t, n;
int a[MAXN][MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2 == 0) a[1][2] = 0;
        for (int i = 3 - n%2; i <= n; i += 2) {
            for (int j = 1; j < i; j++) {
                if (j % 2 == 1) {
                    a[j][i] = 1; a[j][i + 1] = -1;
                } else {
                    a[j][i] = -1; a[j][i + 1] = 1;
                }
                if (n % 2 == 0) a[i][i + 1] = 0; else a[i][i + 1] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cout << a[i][j] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}