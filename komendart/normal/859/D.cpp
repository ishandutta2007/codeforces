#include <bits/stdc++.h>

using namespace std;

const int maxn = 6;

int n;
double p[1 << maxn][1 << maxn];
double chance[1 << maxn][maxn + 1];
double dp[1 << maxn][1 << maxn];

void dfs1(int depth, int tl, int tr) {
    if (depth == 0) {
        chance[tl][0] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    dfs1(depth - 1, tl, tm);
    dfs1(depth - 1, tm + 1, tr);
    for (int i = tl; i <= tm; ++i) {
        for (int j = tm + 1; j <= tr; ++j) {
            double tmp = chance[i][depth - 1] * chance[j][depth - 1];
            chance[i][depth] += tmp * p[i][j];
            chance[j][depth] += tmp * p[j][i];
        }
    }
}

double f(int v, int tl, int tr, int depth) {
    if (depth == 0) {
        return 0;
    }
    int tm = (tl + tr) / 2;
    if (v <= tm) {
        return chance[v][depth] * (1 << (depth - 1)) + dp[tm + 1][tr] + f(v, tl, tm, depth - 1);
    } else {
        return chance[v][depth] * (1 << (depth - 1)) + dp[tl][tm] + f(v, tm + 1, tr, depth - 1);
    }
}

void dfs2(int depth, int tl, int tr) {
    if (depth == 0) {
        dp[tl][tr] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    dfs2(depth - 1, tl, tm);
    dfs2(depth - 1, tm + 1, tr);
    for (int i = tl; i <= tm; ++i) {
        dp[tl][tr] = max(dp[tl][tr], f(i, tl, tr, depth));
        if (i == 1) {
            //cerr << f(i, depth) << endl;
        }
    }
    for (int i = tm + 1; i <= tr; ++i) {
        dp[tl][tr] = max(dp[tl][tr], f(i, tl, tr, depth));
    }
    //cerr << tl << ' ' << tr << ' ' << dp[tl][tr] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            int x; cin >> x;
            p[i][j] = x / 100.0;
        }
    }

    dfs1(n, 0, (1 << n) - 1);
    dfs2(n, 0, (1 << n) - 1);
    cout << fixed; cout.precision(12);
    cout << dp[0][(1 << n) - 1];
}