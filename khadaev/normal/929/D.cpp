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

const int N = 1e5 + 100;
vector<int> e[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, a, b;
    cin >> n >> a >> b;
    --a, --b;
    vector<int> g(n - 1);
    cin >> g;
    map<int, set<int>> k;
    forn(i, 0, n) {
        int x;
        cin >> x;
        k[x].insert(i);
    }
    forn(i, 0, a)
        e[i].eb(i + 1);
    forn(i, a + 1, n)
        e[i].eb(i - 1);
    int pos = a;
    ford(i, 0, a) {
        auto& st = k[g[i]];
        auto it = st.upper_bound(i);
        if (it == st.end()) break;
        setmax(pos, *it);
        e[pos].eb(i);
    }
    pos = a;
    forn(i, a + 1, n) {
        auto& st = k[g[i - 1]];
        auto it = st.lower_bound(i);
        if (it == st.begin()) break;
        --it;
        setmin(pos, *it);
        e[pos].eb(i);
    }
    /*
    forn(i, 0, n) {
        for (int j : e[i])
            cerr << i << ' ' << j << '\n';
    }
    */
    //Dijkstra is so hard :(
    vector<ll> dist(n, LINF);
    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> q;
    q.emplace(0, a);
    while (!q.empty()) {
        auto [dst, u] = q.top();
        q.pop();
        if (dist[u] != LINF) continue;
        dist[u] = dst;
        for (int v : e[u])
            q.emplace(dst + abs(u - v), v);
    }
    cout << (dist[b] == LINF ? -1 : dist[b]) << '\n';
}