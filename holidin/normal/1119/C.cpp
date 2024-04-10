#include <bits/stdc++.h>
using namespace std;
const int N  = 1e3 + 1;
int a[N][N];
int main() {
    int i, j, k, n, m, b, s;
    long long h, h1;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; ++i)
    for (j = 0; j < k; ++j)
        cin >> a[i][j];
    for (i = 0; i < n; ++i)
    for (j = 0; j < k; ++j) {
        cin >> m;
        a[i][j] ^= m;
    }
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < k - 1; ++j)
        if (a[i][j] == 1) {
            a[i][j] = 0;
            a[i][j + 1] = !a[i][j + 1];
            a[i + 1][j] = !a[i + 1][j];
            a[i + 1][j + 1] = !a[i + 1][j + 1];
        }
        if (a[i][k - 1] == 1) {
            cout << "No";
            return 0;
        }
    }
    for (j = 0; j < k; ++j)
    if (a[n - 1][j] == 1) {
        cout << "No";
        return 0;
    }
    cout << "Yes";
}