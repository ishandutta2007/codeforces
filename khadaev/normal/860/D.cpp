#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
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

const int N = 2e5 + 10;
vector<int> e[N], ch[N];
int p[N];
char used1[N];

vector<int> tree[N];
vector<int> comp;

vector<tuple<int, int, int>> ans;
set<pair<int, int>> usedE;

void dfs1(int i) {
    if (used1[i]) return;
    used1[i] = 1;
    comp.eb(i);
    for (int j : e[i]) if (!used1[j]) {
        tree[i].eb(j);
        tree[j].eb(i);
        dfs1(j);
    }
}

void dfs2(int i, int par) {
    p[i] = par;
    for (int j : tree[i]) if (j != par) {
        ch[i].eb(j);
        dfs2(j, i);
    }
}

bool dfs3(int i, int par) {
    vector<int> free;
    for (int j : ch[i]) {
        if (dfs3(j, i))
            free.eb(j);
    }
    for (int j : e[i]) {
        if (j == par || p[j] == i) continue;
        if (usedE.find({i, j}) == usedE.end())
            free.eb(j);
    }
    int sz = free.size();
    //cerr << i << ' ' << sz << '\n';
    forn(j, 0, sz / 2) {
        ans.eb(free[2 * j], i, free[2 * j + 1]);
        usedE.emplace(free[2 * j], i);
        usedE.emplace(free[2 * j + 1], i);
        usedE.emplace(i, free[2 * j]);
        usedE.emplace(i, free[2 * j + 1]);
    }
    if (sz % 2) {
        ans.eb(free.back(), i, par);
        usedE.emplace(free.back(), i);
        usedE.emplace(par, i);
        usedE.emplace(i, free.back());
        usedE.emplace(i, par);
    }
    return 1 - sz % 2;
}

void solve(int i) {
    dfs1(i);
    if (comp.size() <= 2) {
        comp.clear();
        return;
    }
    for (int j : comp) if (tree[j].size() == 1) {
        i = j;
        break;
    }
    dfs2(i, -1);
    int j = ch[i][0];
    bool odd = dfs3(j, i);
    vector<int> free;
    if (odd) free.eb(j);
    for (int q : e[i])
        if (q != j && usedE.find({q, i}) == usedE.end())
            free.eb(q);
    int sz = free.size();
    forn(q, 0, sz / 2) {
        ans.eb(free[2 * q], i, free[2 * q + 1]);
        usedE.emplace(free[2 * q], i);
        usedE.emplace(free[2 * q + 1], i);
        usedE.emplace(i, free[2 * q]);
        usedE.emplace(i, free[2 * q + 1]);
    }


    comp.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
    }
    forn(i, 0, n) if (!used1[i]) solve(i);
    cout << ans.size() << '\n';
    for (auto q : ans) {
        int x, y, z;
        tie(x, y, z) = q;
        cout << 1 + x << ' ' << 1 + y << ' ' << 1 + z << '\n';
    }
}