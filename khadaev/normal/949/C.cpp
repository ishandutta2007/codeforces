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

const int N = 1e5 + 10;
vector<int> e[N], er[N];
int tim = -1;

vector<int> order;
char used[N], here[N];
int comp[N];

void dfs1(int u) {
    used[u] = 1;
    for (int v : e[u])
        if (!used[v])
            dfs1(v);
    order.eb(u);
}

void dfs2(int u) {
    used[u] = 1;
    comp[u] = tim;
    for (int v : er[u])
        if (!used[v])
            dfs2(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> t(n);
    cin >> t;
    while (m--) {
        int c1, c2;
        cin >> c1 >> c2;
        --c1, --c2;
        forn(i, 0, 2) {
            if (t[c1] + 1 == t[c2] || (t[c1] == h - 1 && t[c2] == 0))
                e[c1].eb(c2);
            swap(c1, c2);
        }
    }
    ford(u, 0, n) for (int v : e[u])
        er[v].eb(u);
    forn(u, 0, n) if (!used[u]) dfs1(u);
    memset(used, 0, sizeof used);
    reverse(all(order));
    for (int x : order)
        if (!used[x]) {
            ++tim;
            dfs2(x);
        }
    vector<int> sz(tim + 1), bad(tim + 1);
    forn(u, 0, n) {
        ++sz[comp[u]];
        for (int v : e[u])
            if (comp[u] != comp[v])
                bad[comp[u]] = 1;
    }
    int opt = 0;
    forn(i, 0, tim + 1) {
        if (bad[i]) continue;
        if (bad[opt] || sz[i] < sz[opt])
            opt = i;
    }
    cout << sz[opt] << '\n';
    forn(u, 0, n)
        if (comp[u] == opt)
            cout << u + 1 << ' ';
    cout << '\n';
}