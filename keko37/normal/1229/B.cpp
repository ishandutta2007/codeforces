#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;
const int LOG = 19;
const int MOD = 1000000007;

llint n, sol;
llint w[MAXN];
vector <int> v[MAXN];
int par[LOG][MAXN], dub[MAXN];
llint g[LOG][MAXN];

void dfs (int x, int rod) {
    dub[x] = 1 + dub[rod];
    par[0][x] = rod;
    g[0][x] = __gcd(w[x], w[rod]);
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        dfs(sus, x);
    }
}

void precompute () {
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
            g[i][j] = __gcd(g[i - 1][j], g[i - 1][par[i - 1][j]]);
        }
    }
}

int isti (int x, llint val) {
    for (int i = LOG - 1; i >= 0; i--) {
        int nxt = par[i][x];
        if (nxt == 0) continue;
        llint novi = __gcd(val, g[i][x]);
        if (novi == val) {
            x = nxt;
        }
    }
    return x;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> w[i];
    }
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    precompute();
    for (int i=1; i<=n; i++) {
        llint curr = i, val = w[i];
        int cnt = 0;
        while (curr != 0) {
            cnt++;
            int nxt = isti(curr, val);
            sol = (sol + (dub[curr] - dub[nxt] + 1) * val) % MOD;
            curr = par[0][nxt];
            val = __gcd(val, w[curr]);
        }
    }
    cout << sol;
    return 0;
}