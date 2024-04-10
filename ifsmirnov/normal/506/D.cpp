#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;
const int maxn = 100500;
const int K = 200;

int p[maxn], rk[maxn];
void init(int n) {
    forn(i, n) p[i] = i, rk[i] = 1;
}
int get(int x) { return p[x] == x ? x : (p[x] = get(p[x])); }
void unite(int x, int y) {
    x = get(x); y = get(y);
    if (x == y) return;
    if (rk[x] < rk[y]) p[x] = y;
    else {
        if (rk[x] == rk[y]) rk[x] += rk[y];
        p[y] = x;
    }
}

vector<pii> e[maxn];
int qu[maxn], qv[maxn];
map<pii, int> add;
int res[maxn];
int n, m, q;
vector<int> cols;

void scan() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c), --u,--v,--c;
        e[c].pb(mp(min(u, v), max(u, v)));
        cols.pb(c);
    }
    scanf("%d", &q);
    forn(i, q) {
        scanf("%d%d", &qu[i], &qv[i]), --qu[i], --qv[i];
        if (qu[i] > qv[i]) swap(qu[i], qv[i]);
    }
}

void solve_big(int c) {
    init(n);
    for (auto edge: e[c]) {
        unite(edge.fi, edge.se);
    }
    forn(i, q) {
        res[i] += get(qu[i]) == get(qv[i]);
    }
}

void solve_small(int c) {
    vector<int> vs;
    for (auto edge: e[c]) {
        p[edge.fi] = edge.fi;
        rk[edge.fi] = 1;
        p[edge.se] = edge.se;
        rk[edge.se] = 1;
        vs.pb(edge.fi);
        vs.pb(edge.se);
    }
    for (auto edge: e[c]) {
        unite(edge.fi, edge.se);
    }
    sort(all(vs));
    vs.erase(unique(all(vs)), vs.end());
    for (auto u: vs) for (auto v: vs) if (u < v && get(u) == get(v)) ++add[mp(u, v)];
}

void solve() {
    sort(all(cols));
    cols.erase(unique(all(cols)), cols.end());
//     for (auto t: cols) cout << t << " ";
//     cout << endl;
    for (auto c: cols) {
        if ((int)e[c].size() <= K) {
            solve_small(c);
        } else {
            solve_big(c);
        }
    }
    forn(i, q) {
        if (add.count(mp(qu[i], qv[i]))) {
            res[i] += add[mp(qu[i], qv[i])];
        }
        printf("%d\n", res[i]);
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}