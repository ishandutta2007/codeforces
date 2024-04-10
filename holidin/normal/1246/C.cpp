#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 2e3 + 1;
const int mod = 1e9 + 7;
int dpleft[N][N],  dpup[N][N], str[N][N], stl[N][N];
string s[N];

void solve() {
    int i, j, k, n;
    cin >> n >> k;
    for (i = 0; i < n; ++i)
        cin >> s[i];
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= k; ++j) {
        str[i][j] = str[i][j - 1] + (s[i - 1][j - 1] == 'R');
        stl[i][j] = stl[i - 1][j] + (s[i - 1][j - 1] == 'R');
    }
    dpup[1][1] = 1;
    dpleft[1][1] = 1;
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= k; ++j)
    if (i * j > 1) {
        if (i > 1) {
            int l = 1, r = i + 1;
            while (r - l > 1) {
                int mid = (l + r) / 2 - 1;
                if (stl[n][j] - stl[mid][j] > (n - i))
                    l = mid + 1;
                else
                    r = mid + 1;
            }
            if (l < i)
                dpup[i][j] = (dpup[i][j - 1] + dpleft[i - 1][j] - dpleft[l - 1][j] + mod) % mod;
            else
                dpup[i][j] = dpup[i][j - 1];
        } else
            dpup[i][j] = dpup[i][j - 1];
        if (j > 1) {
            int l = 1, r = j + 1;
            while (r - l > 1) {
                int mid = (l + r) / 2 - 1;
                if (str[i][k] - str[i][mid] > (k - j))
                    l = mid + 1;
                else
                    r = mid + 1;
            }
            if (l < j)
                dpleft[i][j] = (dpleft[i - 1][j] + dpup[i][j - 1] - dpup[i][l - 1] + mod) % mod;
            else
                dpleft[i][j] = dpleft[i - 1][j];
        } else
            dpleft[i][j] = dpleft[i - 1][j];
    }
    int ans = 0;
    for (i = n - 1; i >= 0; --i)
    if (s[i][k - 1] == 'R')
        break;
    else
        ans += dpleft[i + 1][k] - dpleft[i][k];
    cout << (ans % mod + mod) % mod;
}


signed main() {
    int i, j, k, n, p, x;
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}