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
        p[get(v)] = get(u);
    }
};

ll solve(vector<ll> w, vector<vector<int>> e, int s) {
    int n = w.size();

    dsu d(n);
    vector<int> c(n);
    vector<int> in(n), out(n);
    int tmr = 0;
    function<bool(int, int)> dfs = [&](int v, int pr) {
        bool any = 0;

        c[v] = 1;
        in[v] = out[v] = tmr++;
        for (int to : e[v]) {
            if (to == pr) continue;
            if (c[to] == 0) {
                if (dfs(to, v)) {
                    any = 1;
                    d.uni(v, to);
                }
                out[v] = min(out[v], out[to]);
            } else if (c[to] == 1) {
                out[v] = min(out[v], in[to]);
                any = 1;
            } else continue;
        }
        c[v] = 2;
        return any;
    };
    dfs(s, -1);
//    dbv(in);
//    dbv(out);

    vector<vector<int>> g(n);
    for (int v = 0; v < n; v++) {
        for (int u : e[v]) {
            g[d.get(v)].push_back(d.get(u));
            g[d.get(u)].push_back(d.get(v));
        }
    }

    for (int i = 0; i < n; i++) {
        assert(d.get(i) == i || d.get(i) == d.get(s));
    }
    for (int i = 0; i < n; i++) {
        if (d.get(i) != i) {
            w[d.get(i)] += w[i];
        }
    }

    ll ans = -1;
    vector<char> vis(n);
    function<void(int, ll)> dfs2 = [&](int v, ll sum) {
//        db2(v, sum);
        sum += w[v];
        ans = max(ans, sum);
        vis[v] = 1;
        for (int to : g[v]) {
            if (vis[to]) continue;
            dfs2(to, sum);
        }
    };
    dfs2(d.get(s), 0);

    return ans;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<ll> w(n);
        for (int i = 0; i < n; i++) scanf("%lld", &w[i]);
        vector<vector<int>> e(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int s;
        scanf("%d", &s);
        s--;

        printf("%lld\n", solve(w, e, s));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}