#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 2e5 + 10;

bool dp[N][10][10];
short int ls[N][10][10], c[N][10][10];
int x[N], y[N], a[N];

void solve() {
    int i, j, k, n, l;
    string s;
    cin >> n;
    cin >> s;
    for (i = 0; i < s.size(); ++i)
        a[i] = s[i] - '0';
    bool can = 0;
    for (int g = 0; g < 10; ++g)
    if (!can) {
        for (i = 0; i <= n; ++i)
        for (j = 0; j < 10; ++j)
        for (l = 0; l < 10; ++l)
            dp[i][j][l] = 0;
        dp[0][0][g] = 1;
        for (i = 0; i <= n; ++i)
        for (j = 0; j < 10; ++j)
        for (l = 0; l < 10; ++l)
        if  (dp[i][j][l]) {
            if (a[i] >= j) {
                dp[i + 1][max(j, a[i])][l] = 1;
                ls[i + 1][max(j, a[i])][l] = 1;
                c[i + 1][max(j, a[i])][l] = j;
            }
            if (a[i] >= l) {
                dp[i + 1][j][max(a[i], l)] = 1;
                ls[i + 1][j][max(a[i], l)] = 2;
                c[i + 1][j][max(a[i], l)] = l;
            }
        }
        bool flag = 0;
        for (i = 0; i <= g; ++i)
        for (j = g; j < 10; ++j)
        if (dp[n][i][j] && !flag) {
            flag = 1;
            int x = i, y = j;
            vector <int> ans;
            for (l = n; l > 0; --l) {
                ans.push_back(ls[l][x][y]);
                if (!dp[l][x][y])
                    exit(1);
                if (ls[l][x][y] == 1)
                    x = c[l][x][y];
                else
                    y = c[l][x][y];
            }
            for (l = ans.size() - 1; l >= 0; --l)
                cout << ans[l];
            cout << "\n";
            can = 1;
        }
    }
    if (!can)
        cout << '-' << "\n";
}

int main() {
    int i, j, k, test;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> test;
    for (i = 0; i < test; ++i)
        solve();
}