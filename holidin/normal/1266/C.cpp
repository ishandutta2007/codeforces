#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e3 + 1;
int m[N][N];
void solve() {
    int i, j, k, n, t;
    string s;
    cin >> n >> k;
    bool flag = 0;
    if (n > k) {
        swap(n, k);
        flag = 1;
    }
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= k; ++j)
            m[i][j] = (n + j) * i;
    }
    if (n == 1 && k == 1) {
        cout << 0;
        return;
    }
    if (flag)
        swap(n, k);
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= k; ++j)
        if (flag)
            cout << m[j][i] << ' ';
        else
            cout << m[i][j] << ' ';
        cout << endl;
    }
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();
}