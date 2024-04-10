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

const int N = 3e5 + 10;
vector<int> e[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> edges;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
        edges.emplace(u, v);
        edges.emplace(v, u);
    }
    forn(i, 0, n) sort(all(e[i]));
    vector<int> ans;
    vector<int> dist(n, INF), par(n);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : e[u])
            if (dist[v] == INF) {
                dist[v] = 1 + dist[u];
                par[v] = u;
                q.push(v);
            }
    }
    if (dist[n - 1] != INF) {
        int v = n - 1;
        while (v) {
            ans.eb(v);
            v = par[v];
        }
        ans.eb(0);
        reverse(all(ans));
    }
    vector<int> near(n);
    for (int v : e[0])
        near[v] = 1;
    for (int v : e[0])
        for (int w : e[v])
            if (w != 0 && !near[w]) {
                vector<int> tmp = {0, v, w, 0, n - 1};
                if (tmp.size() < ans.size() || ans.empty())
                    ans = tmp;
            }
    if (ans.empty() || ans.size() > 6) {
        dist = vector<int>(n, INF);
        for (int i : e[0])
            if (dist[i] == INF) {
                if (ans.size() == 6) break;
                vector<int> used;
                q.push(i);
                dist[i] = 0;
                used.eb(i);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : e[u])
                        if (dist[v] == INF && v != 0) {
                            dist[v] = 1 + dist[u];
                            q.push(v);
                            used.eb(v);
                        }
                }
                for (int u : used) {
                    if (ans.size() == 6) break;
                    for (int v : used) if (u != v)
                        if (edges.find({u, v}) == edges.end()) {
                            int w = -1;
                            forn(x, 0, n)
                                if (x != u && x != v && x != 0 && edges.find({u, x}) != edges.end() && edges.find({v, x}) != edges.end()) {
                                    w = x;
                                    break;
                                }
                            assert(w != -1);
                            ans = {0, u, w, v, u, n - 1};
                            break;
                        }
                }
            }
    }
    cout << int(ans.size()) - 1 << '\n';
    for (int x : ans) cout << 1 + x << ' ';
    return 0;
}