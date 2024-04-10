#include <bits/stdc++.h>
using namespace std;
const int N = 501;
const int inf = 1e9;
int dp[N][N][11], go[N][10], d[N], top = 0;

void add_string(string s, int t) {
    int u = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (go[u][s[i] - '0'] == 0) {
            ++top;
            go[u][s[i] - '0'] = top;
        }
        u = go[u][s[i] - '0'];
    }
    d[u] += t;
}

void f(int a, int c) {
    int i, j, l;
    int p[11][11];
    for (int i = 0; i < 11; ++i)
    for (int j = 0; j < 11; ++j)
        p[i][j] = inf;
    for (int i = 0; i < 11; ++i)
        p[0][i] = d[a] * c;
    for (i = 0; i <= 9; ++i)
    for (j = 0; j <= 10; ++j)
    if (p[i][j] < inf)
            if (go[a][i] == 0)
                p[i + 1][j] = min(p[i + 1][j], p[i][j]);
        else
            for (l = 0; l <= 10 - j; ++l)
                p[i + 1][j + l] = min(p[i + 1][j + l], p[i][j] + dp[go[a][i]][c + 1][l]);
    for (i = 0; i <= 10; ++i)
    if (c > 0 && i > 0)
        dp[a][c][i] = min(dp[a][0][i - 1], p[10][i]);
    else
        dp[a][c][i] = p[10][i];

}

int main() {
    string s;
    int i, j, n, k, l;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        cin >> s >> j;
        add_string(s, j);
    }
    for (i = top; i >= 0; --i)
    for (j = 0; j <= i; ++j)
        f(i, j);
    cout << dp[0][0][k];
}