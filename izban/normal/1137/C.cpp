#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;

const int N = 1.01e5;
const int D = 53;

int n, m, d;
vector<int> e[N], g[N];
char a[N][D];

vector<int> vct;
int last[N], tmr;
int c[N], cc;
void dfs1(int v) {
    if (last[v] == tmr) return;
    last[v] = tmr;
    for (int to : e[v]) {
        dfs1(to);
    }
    vct.push_back(v);
}

void dfs2(int v) {
    if (c[v] != -1) return;
    c[v] = cc;
    for (int to : g[v]) {
        dfs2(to);
    }
}

struct dsu {
    int n;
    vector<int> p;

    dsu(int _n) {
        n = _n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int get(int x) {
        return x == p[x] ? x : p[x] = get(p[x]);
    }

    void uni(int u, int v) {
        u = get(u);
        v = get(v);
        p[v] = u;
    }
};

int add[N * D], dp[N * D];
vector<int> shit[N * D];

void init() {
    for (int i = 0; i < n; i++) {
        e[i].clear();
        g[i].clear();
    }
    for (int i = 0; i < n * d; i++) shit[i].clear();

    for (int i = 0; i < n * d; i++) {
        dp[i] = -1;
        add[i] = 0;
    }
    vct.clear();
    for (int i = 0; i < n; i++) c[i] = -1;
}

int solve() {
    tmr++;
    for (int i = 0; i < n; i++) {
        dfs1(i);
    }
    reverse(vct.begin(), vct.end());
    tmr++;
    cc = 0;
    for (int i = 0; i < n; i++) {
        int v = vct[i];
        if (c[v] != -1) continue;
        dfs2(v);
        cc++;
    }

    dsu ds(n * d);
    for (int v = 0; v < n; v++) {
        for (int to : e[v]) {
            if (c[to] == c[v]) {
                for (int i = 0; i < d; i++) {
                    ds.uni(v * d + i, to * d + (i + 1) % d);
                }
            }
        }
    }
    for (int i = 0; i < n * d; i++) shit[ds.get(i)].push_back(i);

    for (int cur = 0; cur < n * d; cur++) {
        tmr++;
        int cres = 0;
        for (int vt : shit[cur]) {
            int v = vt / d;
            int t = vt % d;

            if (a[v][t] && last[v] != tmr) {
                last[v] = tmr;
                cres++;
            }
        }
        add[cur] = cres;
    }

    dp[ds.get(0)] = 0;

    for (int v : vct) {
        for (int t = 0; t < d; t++) {
            int vt = v * d + t;
            int pr = ds.get(vt);

            if (dp[pr] == -1) continue;

            if (add[pr] != -1) {
                dp[pr] += add[pr];
                add[pr] = -1;
            }
            for (int to : e[v]) {
                if (c[to] != c[v]) {
                    int nvt = to * d + (t + 1) % d;
                    int npr = ds.get(nvt);
                    dp[npr] = max(dp[npr], dp[pr]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n * d; i++) ans = max(ans, dp[i]);
    return ans;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    while (scanf("%d%d%d", &n, &m, &d) == 3) {
        init();
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            e[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", a[i]);
            for (int j = 0; j < d; j++) a[i][j] -= '0';
        }

        printf("%d\n", solve());
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}