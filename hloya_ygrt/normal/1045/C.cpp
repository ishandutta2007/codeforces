//           
//         
//     
//     
//        
//           
#include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
using namespace std;

#define fst first
#define snd second
#define mp make_pair
//#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

#define ADD_OPERATORS_IN(T, COMP) \
    bool operator < (const T& ot) const { return COMP(ot) == -1; } \
    bool operator > (const T& ot) const { return COMP(ot) == 1; } \
    bool operator == (const T& ot) const { return COMP(ot) == 0; } \
    bool operator != (const T& ot) const { return COMP(ot) != 0; }

#define ADD_OPERATORS_OUT(T, COMP) \
    bool operator < (const T& a, const T& b) const { return COMP(a, b) == -1; } \
    bool operator > (const T& a, const T& b) const { return COMP(a, b) == 1; } \
    bool operator == (const T& a, const T&b) const { return COMP(a, b) == 0; } \
    bool operator != (const T& a, const T&b) const { return COMP(a, b) != 0; }


typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 1e6 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 9;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
const int pp = 41;
#define next ajksdslk

int used[maxn];
vector<pair<int, int> > t[maxn];

int up_cost[maxn], up[maxn];

int p[maxn];

int find(int v) {
    if (v == p[v]) return v;
    return p[v] = find(p[v]);
}

void un(int u, int v) {
    u = find(u);
    v = find(v);
    if (rand() % 2) swap(u, v);
    p[u] = v;
}

void dfs(int v, int p = -1) {
    for (auto e : t[v]) {
        int to = e.first, cost = e.second;
        if (to != p) {
            dfs(to, v);
            up[to] = v;
            up_cost[to] = cost;
        }
    }
}

int sum_up[maxn];

const int L = 23;
int upp[maxn][L];

int timer = 0;
int tin[maxn];
int tout[maxn];

void dfs2(int v) {
    upp[v][0] = max(up[v], 0);
    for (int i= 1; i < L; i ++) {
        upp[v][i] = upp[ upp[v][i - 1]][i - 1];
    }
    tin[v] = ++timer;
    sum_up[v] += up_cost[v];
    for (auto e : t[v]) {
        sum_up[e.first] = sum_up[v];
        dfs2(e.first);
    }
    tout[v] = timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=L-1; i>=0; --i)
        if (! upper (upp[a][i], b))
            a = upp[a][i];
    return upp[a][0];
}

int main() {
//    freopen("kek.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }


    vector<pair<int, int> > e, e2;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e.pb(mp(u, v));
    }

    for (auto c : e) {
        if (find(c.first) != find(c.second)) {
            t[c.first].pb(mp(c.second, 2));
            t[c.second].pb(mp(c.first, 2));
//            cerr << c.first << ' ' << c.second << endl;
            un(c.first, c.second);
        } else e2.pb(c);
    }
    e = e2;
//    return 0;

    up[0] = -1;
    up_cost[0] = 0;
    dfs(0);


    int timer = 1;
    vector<int> p, g;

    int f_v = n;
    for (auto c : e) {
        int u = c.first, v = c.second;
        p.clear();
        g.clear();
        timer++;

        int a = u;
        for (int i = 0; i < 32; i++) {
            p.push_back(a);
            used[a] = timer;
//            cerr << a << endl;
//            return 0;
            a = up[a];
            if (a == -1) break;
        }

        a = v;
        for (int i = 0; used[a] != timer; i++) {
            g.push_back(a);
            used[a] = timer;
            a = up[a];
        }

        while (p.back() != a) p.pop_back();

        int new_vertice = f_v;
        f_v++;

        up[new_vertice] = a;
        up_cost[new_vertice] = 1;

        if (a >= n)
            up_cost[new_vertice] = 0;

        for (int i = 0; i + 1 < p.size(); i++) {
            up[p[i]] = new_vertice;
            if (p[i] >= n)
                up_cost[p[i]] = 0;
            else
                up_cost[p[i]] = 1;
        }
        for(int i : g) {
            up[i] = new_vertice;
            if (i >= n)
                up_cost[i] = 0;
            else
                up_cost[i] = 1;
        }
    }

//    return 0;
    for (int i = 0; i < maxn; i++)
        t[i].clear();

    for (int i = 1; i < f_v; i++) {
        int v = up[i];
        int c = up_cost[i];

        t[v].pb(mp(i, c));
    }

    dfs2(0);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int l = lca(a, b);
        int ans = sum_up[a] + sum_up[b] - 2 * sum_up[l];
        cout << ans / 2 << "\n";
    }
}