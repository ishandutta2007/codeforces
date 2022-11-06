#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n) - 1; i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

struct Edge {
    int u, v, w, ix;

    Edge () {}

    bool operator< (const Edge& ot) const {
        return w == ot.w ? ix < ot.ix : w < ot.w;
    }
};

const int N = 5e5 + 10;
int p[N];

int get(int x) {
    return x == p[x] ? x : p[x] = get(p[x]);
}

pair<int, int> eds[N];

int _get (int x, vector<int>& pr) {
    return x == pr[x] ? x : pr[x] = _get(pr[x], pr);
}

bool forest(vector<int> e) {
    //trace(e);
    int sz = 0;
    for (int x : e) {
        int u = eds[x].fs, v = eds[x].sn;
        setmax(sz, u);
        setmax(sz, v);
    }
    vector<int> pr(sz + 1);
    for (int x : e) {
        int u = eds[x].fs, v = eds[x].sn;
        //cerr << u << ' ' << v << '\n';
        pr[u] = u, pr[v] = v;
    }
    for (int x : e) {
        int u = eds[x].fs, v = eds[x].sn;
        //cerr << "BEF: " << u << ' ' << v << '\n';
        u = _get(u, pr), v = _get(v, pr);
        //cerr << "AFT: " << u << ' ' << v << '\n';
        if (u == v) return false;
        pr[u] = v;
    }
    return true;
}

int main() {
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, m;
    scanf("%d %d", &n, &m);
    forn(i, 0, n) p[i] = i;
    vector<int> ws(m);
    vector<Edge> e(m);
    forn(i, 0, m) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
        ws[i] = e[i].w;
        e[i].ix = i;
        --e[i].u, --e[i].v;
    }
    sort(all(e));
    vector<Edge> cur;
    forn(i, 0, m) {
        cur.eb(e[i]);
        if (i == m - 1 || e[i].w != e[i + 1].w) {
            map<int, int> compress;
            for (Edge x : cur) {
                compress[get(x.u)];
                compress[get(x.v)];
            }
            int ix = -1;
            for (auto& r : compress)
                r.sn = ++ix;
            for (Edge x : cur) {
                eds[x.ix] = {compress[get(x.u)], compress[get(x.v)]};
            }
            for (Edge x : cur) {
                int u = get(x.u), v = get(x.v);
                p[u] = v;
            }
            cur.clear();
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int k;
        scanf("%d", &k);
        vector<int> y(k);
        forn(i, 0, k) {
            scanf("%d", &y[i]);
            --y[i];
        }
        sort(all(y), [&](int i, int j) {
                return ws[i] < ws[j];
                });
        bool ok = true;
        vector<int> curr;
        forn(i, 0, k) {
            curr.eb(y[i]);
            if (i == k - 1 || ws[y[i]] != ws[y[i + 1]]) {
                if (!forest(curr)) {
                    ok = false;
                    break;
                }
                curr.clear();
            }
        }
        printf(ok ? "YES\n" : "NO\n");
    }
}