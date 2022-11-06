#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
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

template<typename T, typename S>
istream& operator>> (istream& in, pair<S, T>& p) {
    in >> p.fs >> p.sn;
    return in;
}
template<typename T, typename S>
ostream& operator<< (ostream& out, pair<S, T>& p) {
    out << p.fs << ' ' << p.sn << ' ';
    return out;
}

template<typename T>
istream& operator>> (istream& in, vector<T>& v) {
    for (T& x : v) in >> x;
    return in;
}
template<typename T>
ostream& operator<< (ostream& out, vector<T>& v) {
    for (T& x : v) out << x << ' ';
    return out;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1 << 17;

int vis[N * 4 + 100];

struct line {
    ll k, b;
    line(ll _k = 0, ll _b = -LINF) {
        k = _k; b = _b;
    }
    ll get(ll x) {
        return k * x + b;
    }
} c[N * 4 + 100];

vector<int> used;
vector<pair<int, line>> changed;

void modify(int x, int l, int r, line v) {
    //cerr << "modify\n";
    if (!vis[x]) {
        vis[x] = 1;
        c[x] = v;
        used.eb(x);
        return;
    }
    if (c[x].get(l) > v.get(l) && c[x].get(r) > v.get(r))
        return;
    if (c[x].get(l) < v.get(l) && c[x].get(r) < v.get(r)) {
        changed.eb(x, c[x]);
        c[x] = v;
        return;
    }
    if (l == r) return;
    int m = (l + r + 2 * N) / 2 - N;
    if (c[x].get(l) < v.get(l)) {
        changed.eb(x, c[x]);
        swap(c[x], v);
    }
    if (c[x].get(m) > v.get(m))
        modify(2 * x + 1, m + 1, r, v);
    else {
        changed.eb(x, c[x]);
        swap(c[x], v);
        modify(2 * x, l, m, v);
    }
}

ll get(int x, int l, int r, int pos) {
    //cerr << "get\n";
    //cerr << x << '\n';
    //cerr << l << ' ' << r << '\n';
    if (l == r) return c[x].get(l);
    int m = (l + r + 2 * N) / 2 - N; ll ans = c[x].get(pos);
    if (pos <= m) ans = max(ans, get(2 * x, l, m, pos));
    else ans = max(ans, get(2 * x + 1, m + 1, r, pos));
    return ans;
}

int a[N], b[N], sz[N];
vector<int> e[N], ch[N];

void dfs1(int u, int p) {
    sz[u] = 1;
    for (int v : e[u])
        if (v != p) {
            ch[u].eb(v);
            dfs1(v, u);
            sz[u] += sz[v];
        }
}

ll ans[N];

void dfs3(int);

void dfs2(int u, char keep) {
    auto usz = used.size(), csz = changed.size();
    forn(i, 0, ch[u].size())
        if (sz[ch[u][i]] > sz[ch[u][0]])
            swap(ch[u][i], ch[u][0]);
    forn(i, 1, ch[u].size())
        dfs2(ch[u][i], false);
    if (!ch[u].empty())
        dfs2(ch[u][0], true);
    forn(i, 1, ch[u].size())
        dfs3(ch[u][i]);
    if (ch[u].empty()) ans[u] = 0;
    else ans[u] = -get(1, -N, N - 1, a[u]);
    if (keep) {
        modify(1, -N, N - 1, line(-b[u], -ans[u]));
    } else {
        while (changed.size() > csz) {
            auto& [pos, ln] = changed.back();
            c[pos] = ln;
            changed.pop_back();
        }
        while (used.size() > usz) {
            int pos = used.back();
            vis[pos] = 0;
            c[pos] = line();
            used.pop_back();
        }
    }
}

void dfs3(int u) {
    modify(1, -N, N - 1, line(-b[u], -ans[u]));
    for (int v : ch[u])
        dfs3(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];
    forn(i, 1, n) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v), e[v].eb(u);
    }
    dfs1(0, -1);
    dfs2(0, true);
    forn(i, 0, n) cout << ans[i] << ' ';
}