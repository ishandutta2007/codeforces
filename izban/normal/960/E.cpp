#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

const int N = 1 << 18;
const int MOD = (int)1e9 + 7;

void add(int &x, ll y) {
    x = (x + y) % MOD;
}

int n;
vector<int> e[N];
int a[N];
int alive[N];
int vis[N], tmr;
int cnt[N];

void dfs1(int v) {
    vis[v] = tmr;
    cnt[v] = 1;
    for (int to : e[v]) {
        if (!alive[to] || vis[to] == tmr) continue;
        dfs1(to);
        cnt[v] += cnt[to];
    }
}

int sum[N];

int dp[N][2];

void dfs2(int v, int h) {
    dp[v][0] = dp[v][1] = 0;

    dp[v][h]++;
    vis[v] = tmr;
    for (int to : e[v]) {
        if (!alive[to] || vis[to] == tmr) continue;
        dfs2(to, h ^ 1);
        dp[v][0] += dp[to][0];
        dp[v][1] += dp[to][1];
    }
}

int ROOT;
void dfs3(int v, int h) {
    add(sum[v], 2LL * dp[ROOT][h] * dp[v][h]);
    add(sum[v], MOD - 2LL * dp[ROOT][h ^ 1] * dp[v][h ^ 1] % MOD);
    vis[v] = tmr;
    for (int to : e[v]) {
        if (!alive[to] || vis[to] == tmr) continue;
        dfs3(to, h ^ 1);
    }
}

void solve(int v) {
    tmr++;
    dfs1(v);
    int all = cnt[v], pr = -1;
    while (1) {
        bool f = 0;
        for (int to : e[v]) {
            if (to == pr || !alive[to]) continue;
            if (cnt[to] * 2 >= all) {
                f = 1;
                pr = v;
                v = to;
                break;
            }
        }
        if (!f) break;
    }
    alive[v] = 0;

    tmr++;
    dfs2(v, 0);

    add(sum[v], 1LL * dp[v][0] * dp[v][0]);
    add(sum[v], MOD - 1LL * dp[v][1] * dp[v][1] % MOD);
    for (int to : e[v]) {
        if (!alive[to]) continue;
        add(sum[v], MOD - 1LL * dp[to][0] * dp[to][0] % MOD);
        add(sum[v], 1LL * dp[to][1] * dp[to][1] % MOD);
    }

    ROOT = v;
    for (int to : e[v]) {
        if (!alive[to]) continue;
        dp[v][0] -= dp[to][0];
        dp[v][1] -= dp[to][1];
        tmr++;
        dfs3(to, 1);
        dp[v][0] += dp[to][0];
        dp[v][1] += dp[to][1];
    }

    for (int to : e[v]) {
        if (!alive[to]) continue;
        solve(to);
    }
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
            alive[i] = 1;
            sum[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i] = (a[i] % MOD + MOD) % MOD;
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u; --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        solve(0);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            //add(sum[i], MOD - 1);
            add(ans, 1LL * a[i] * sum[i]);
        }

        cout << ans << endl;
    }


#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}