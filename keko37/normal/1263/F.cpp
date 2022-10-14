#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 2005;
const int LOG = 12;
const int INF = 1000000000;

int n, siz[2];
int par[2][LOG][MAXN], red[2][MAXN];
int dub[2][MAXN];
vector <int> v[2][MAXN];
int dp[MAXN][MAXN];

int t;

void dfs (int x) {
    dub[t][x] = dub[t][par[t][0][x]] + 1;
    for (auto sus : v[t][x]) {
        dfs(sus);
    }
}

void precompute () {
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= siz[t]; j++) {
            par[t][i][j] = par[t][i-1][par[t][i-1][j]];
        }
    }
}

int kth (int x, int k) {
    int pot = 0;
    while (k > 0) {
        if (k & 1) x = par[t][pot][x];
        pot++;
        k /= 2;
    }
    return x;
}

int lca (int x, int y) {
    if (dub[t][x] < dub[t][y]) swap(x, y);
    x = kth(x, dub[t][x] - dub[t][y]);
    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[t][i][x] != par[t][i][y]) {
            x = par[t][i][x];
            y = par[t][i][y];
        }
    }
    return par[t][0][x];
}

int calc (int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    int ind = max(x, y) + 1;
    if (ind > n) return 0;
    int res = INF;

    t = 0;
    if (x == 0) {
        int val = dub[t][red[t][ind]] - 1;
        res = min(res, calc(ind, y) + val);
    } else {
        int g = lca(red[t][x], red[t][ind]);
        int val = dub[t][red[t][ind]] - dub[t][g];
        res = min(res, calc(ind, y) + val);
    }

    t = 1;
    if (y == 0) {
        int val = dub[t][red[t][ind]] - 1;
        res = min(res, calc(x, ind) + val);
    } else {
        int g = lca(red[t][y], red[t][ind]);
        int val = dub[t][red[t][ind]] - dub[t][g];
        res = min(res, calc(x, ind) + val);
    }

    return dp[x][y] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (t = 0; t < 2; t++) {
        cin >> siz[t];
        for (int i = 2; i <= siz[t]; i++) {
            cin >> par[t][0][i];
            v[t][par[t][0][i]].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            cin >> red[t][i];
        }
        dfs(1);
        precompute();
    }
    cout << siz[0] + siz[1] - 2 - calc(0, 0);
    return 0;
}