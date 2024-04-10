#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

void uax(int& x, int y) {
    if (x < y) x = y;
}


const int maxn = 500500;

int n;
vector<pii> e[maxn];
int h[maxn];
int s[maxn];
int val[maxn];
int id[1<<22];

int dp[23][maxn];

int res[maxn];

void scan() {
    scanf("%d", &n);
    char tt[5];
    forn(i, n-1) {
        int p;
        scanf("%d%s", &p, tt);
        e[p-1].pb({i+1, tt[0]-'a'});
    }
}

void dfs0(int v) {
    s[v] = 1;
    for (auto kv: e[v]) {
        int to = kv.fi;
        h[to] = h[v] + 1;
        val[to] = val[v] ^ (1<<kv.se);
        dfs0(to);
        s[v] += s[to];
    }

    sort(all(e[v]), [](const pii& a, const pii& b) { return s[a.fi] > s[b.fi]; });
}

void relax(int where, int k, int v) {
    forn(i, 23) {
        int x = i == 22 ? val[v] : (val[v] ^ (1<<i));
        int need = id[x];
        if (need != -1 && dp[k][need] != -1) {
            uax(res[where], h[v] + dp[k][need] - 2 * h[where]);
        }
    }

    for (auto kv: e[v]) relax(where, k, kv.fi);
}

void clear(int k, int v) {
    uax(dp[k][id[val[v]]], h[v]);
    dp[k+1][id[val[v]]] = -1;

    for (auto kv: e[v]) clear(k, kv.fi);
}

void dfs1(int v, int k) {
    assert(s[v] <= (1<<(22-k)));

    if (!e[v].empty()) {
        dfs1(e[v][0].fi, k);
        res[v] = res[e[v][0].fi];
    }

    forn(i, e[v].size()) if (i) {
        int to = e[v][i].fi;
        dfs1(e[v][i].fi, k+1);
        uax(res[v], res[to]);

        relax(v, k, to);
        clear(k, to);
    }

    forn(i, 23) {
        int x = i == 22 ? val[v] : (val[v] ^ (1<<i));
        int need = id[x];
        if (need != -1 && dp[k][need] != -1) {
            uax(res[v], dp[k][need] - h[v]);
        }
    }

    uax(dp[k][id[val[v]]], h[v]);
}

void solve() {
    dfs0(0);
    memset(id, -1, sizeof id);
    memset(dp, -1, sizeof dp);
    int nid = 0;
    forn(i, n) {
        int x = val[i];
        if (id[x] == -1) id[x] = nid++;
    }

    dfs1(0, 0);
    forn(i, n) printf("%d%c", res[i], " \n"[i+1 == n]);
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}