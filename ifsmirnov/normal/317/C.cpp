#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
#define le(x, y) ((x)<=(y)+eps)
#define gt(x, y) ((x)>(y)+eps)
#define ge(x, y) ((x)>=(y)-eps)
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9+100500;
const int maxn = 350;

int p[maxn];
int get(int x) { return (x == p[x]) ? x : (p[x] = get(p[x])); }
bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    p[x] = y;
    return true;
}
void init() { forn(i, maxn) p[i] = i; }

int n, deg[maxn], a[maxn], b[maxn], d[maxn], C;
vi e[maxn];

void scan()
{
    int m;
    scanf("%d%d%d", &n, &C, &m);
    init();
    forn(i, n) scanf("%d", &a[i]);
    forn(i, n) scanf("%d", &b[i]);

    int x, y;
    forn(i, m) {
        scanf("%d%d", &x, &y);
        --x;--y;
        if (unite(x, y)) {
            e[x].pb(y);
            e[y].pb(x);
            ++deg[x];
            ++deg[y];
        }
    }
}

vector<pii> t;
vector<pair<pii, int> > res;
void dfs(int v, int anc)
{
    forn(i, e[v].size()) {
        int to = e[v][i];
        if (to != anc && !d[to]) {
            dfs(to, v);
            t.pb(mp(v, to));
        }
    }
}

void fail(const char* s = "")
{
    //cerr << "Fail " << s << endl;
    cout << "NO" << endl;
    exit(0);
}

void pushall(int x, int y)
{
    int v = min(a[x], C - a[y]);
    if (v) {
        res.pb(mp(mp(x, y),v));
        a[x] -= v;
        a[y] += v;
    }
}
void in(int v)
{
    forn(i, t.size() - 1)
        pushall(t[i].se, t[i].fi);
    int need = b[v] - a[v];
    int fr = -1;
    forn(i, e[v].size()) if (!d[e[v][i]]) fr = e[v][i];
    assert(fr != -1);
    --deg[v]; --deg[fr];
    if (a[fr] < need) {
        fail("not enough water");
    }
    a[fr] -= need;
    a[v] += need;
    res.pb(mp(mp(fr, v), need));
}
void out(int v)
{
    forn(i, t.size() - 1)
        pushall(t[i].fi, t[i].se);
    int need = a[v] - b[v];
    int fr = -1;
    forn(i, e[v].size()) if (!d[e[v][i]]) fr = e[v][i];
    assert(fr != -1);
    --deg[v]; --deg[fr];
    if (C - a[fr] < need) {
        fail("not enough place");
    }
    a[fr] += need;
    a[v] -= need;
    res.pb(mp(mp(v, fr), need));
}

void solve()
{
    while (true) {
        int v = -1;
        forn(i, n) if (!d[i] && deg[i] == 1) {
            v = i;
            break;
        }
        if (v == -1)
            break;

        t.clear();
        dfs(v, -1);
        d[v] = 1;

        if (a[v] < b[v]) in(v);
        else out(v);
    }

    forn(i, n) if (a[i] != b[i]) fail("not equal");

    printf("%d\n", res.size());
    forn(i, res.size()) printf("%d %d %d\n", res[i].fi.fi+1, res[i].fi.se+1, res[i].se);
}

int main()
{
    //freopen("input.txt", "r", stdin);

    scan();
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}