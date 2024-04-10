#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1505;
const int MOD = 998244353;

int n, cnt;
int g[MAXN][MAXN], par[MAXN * 2], siz[MAXN * 2], mx[MAXN * 2], dp[MAXN * 2][MAXN];
pi e[MAXN * MAXN];
set <int> st[MAXN];
vector <int> v[MAXN * 2], leaves[MAXN * 2];

int add (int x, int y) {x += y; if (x >= MOD) return x - MOD; return x;}
int sub (int x, int y) {x -= y; if (x < 0) return x + MOD; return x;}
int mul (int x, int y) {return (llint) x * y % MOD;}

int nadi (int x) {
    if (x == par[x]) return par[x];
    return par[x] = nadi(par[x]);
}

void solve (int x) {
    if (x <= n) {
        siz[x] = 1;
        dp[x][1] = 1;
        leaves[x].push_back(x);
        return;
    }
    int a = v[x][0], b = v[x][1];
    solve(a); solve(b);
    siz[x] = siz[a] + siz[b];
    for (int i = 1; i <= siz[a]; i++) {
        for (int j = 1; j <= siz[b]; j++) {
            dp[x][i + j] = add(dp[x][i + j], mul(dp[a][i], dp[b][j]));
        }
    }
    for (auto i : leaves[a]) leaves[x].push_back(i);
    for (auto i : leaves[b]) leaves[x].push_back(i);
    mx[x] = max(mx[a], mx[b]);
    for (auto i : leaves[a]) {
        for (auto j : leaves[b]) {
            mx[x] = max(mx[x], g[i][j]);
            st[i].erase(g[i][j]);
            st[j].erase(g[i][j]);
        }
    }
    int mn = 1e9;
    for (auto i : leaves[x]) {
        if (!st[i].empty()) mn = min(mn, *st[i].begin());
    }
    if (mx[x] < mn) dp[x][1] = 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
            if (i != j) st[i].insert(g[i][j]);
            e[g[i][j]] = {i, j};
        }
    }
    cnt = n;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 1; i <= n * (n - 1) / 2; i++) {
        int a = e[i].first, b = e[i].second;
        a = nadi(a); b = nadi(b);
        if (a == b) continue;
        cnt++;
        par[a] = par[b] = par[cnt] = cnt;
        v[cnt].push_back(a);
        v[cnt].push_back(b);
    }
    solve(cnt);
    for (int i = 1; i <= n; i++) {
        cout << dp[cnt][i] << " ";
    }
    return 0;
}