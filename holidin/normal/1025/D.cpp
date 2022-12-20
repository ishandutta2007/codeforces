#include <bits/stdc++.h>
using namespace std;
const int N = 702;

int i, j, n, a[N], nd[N][N];
char dp[N][N][2];

int nod(int a, int b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

bool f(int l, int r, bool t) {
    if (dp[l][r][t] == 0) {
        int x;
        if (t == 0)
            x = l - 1;
        else
            x = r + 1;
        if (r - l >= 1) {
            dp[l][r][t] = 2;
            for (int i = l; i <= r; ++i)
            if (nd[x][i] > 1)
                if (f(l, i - 1, 1) && f(i + 1, r, 0)) {
                    dp[l][r][t] = 1;
                    break;
                }
        } else if (r - l == 0)
                dp[l][r][t] = 2 - (int) (nd[x][l] != 1);
            else
                dp[l][r][t] = 1;
    }
    return dp[l][r][t] == 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    a[0] = 0;
    a[n + 1] = 0;
    for (i = 0; i <= n + 1; ++i)
    for (j = 0; j <= n + 1; ++j)
        nd[i][j] = nod(a[i], a[j]);
    if (f(1, n, 0))
        cout << "Yes";
    else
        cout << "No";
}