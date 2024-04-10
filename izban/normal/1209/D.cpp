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
    bool uni(int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v) return 0;
        p[v] = u;
        return 1;
    }
};

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<pair<int, int>> ed(m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &ed[i].first, &ed[i].second);
            ed[i].first--;
            ed[i].second--;
        }

        dsu d(n);
        int ans = 0;
        for (auto o : ed) {
            ans += !d.uni(o.first, o.second);
        }
        cout << ans << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}