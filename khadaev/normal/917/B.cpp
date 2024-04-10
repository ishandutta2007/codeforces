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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 101;
const int S = 26;
const int SZ = 2 * N * N * S;
vector<int> e[SZ], er[SZ];
int q[SZ], t = 0;
char ans[SZ];
int outdeg[SZ];

int n;
inline int state(int i, int j, int ch, int move) {
    return 2 * (ch + S * (i + j * n)) + move;
}

void add(int u, int v) {
    //cerr << u << ' ' << v << '\n';
    e[u].eb(v);
    er[v].eb(u);
}

int sym(int st) {
    return st / 2 % S;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int m;
    cin >> n >> m;
    //n = 100;
    while (m--) {
    //for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        --u, --v;
        //u = i, v = j;
        int ch = int(c - 'a');
        //int ch = rand() % 26;
        forn(i, 0, n)  {
            add(state(u, i, ch, 0), state(v, i, ch, 1));
            add(state(i, u, ch, 1), state(i, v, ch, 0));
        }
    }
    int cnt = 2 * n * n * S;
    //cerr << "cnt: " << cnt << '\n';
    //stack<int> q;
    forn(i, 0, cnt) outdeg[i] = e[i].size();
    forn(i, 0, n) forn(j, 0, n) forn(ch, 0, S - 1) forn(move, 0, 2)
        ++outdeg[state(i, j, ch, move)];
    forn(i, 0, cnt) if (outdeg[i] == 0) q[t++] = i;
    //cerr << "here\n";
    while (t > 0) {
        //int u = q.top();
        //q.pop();
        int u = q[--t];
        /*
        for (int v : e[u])
            if (ans[v] == 0)
                ans[u] = 1;
        */
        for (int v : er[u]) {
            --outdeg[v];
            if (ans[u] == 0)
                ans[v] = 1;
            if (outdeg[v] == 0)
                q[t++] = v;
        }
        if (sym(u) != 0) {
            int v = u - 2;
            --outdeg[v];
            if (outdeg[v] == 0)
                q[t++] = v;
            if (ans[u] == 1)
                ans[v] = 1;
        }
    }
    forn(i, 0, n) {
        forn(j, 0, n) {
            if (ans[state(i, j, 0, 0)]) cout << 'A';
            else cout << 'B';
        }
        cout << '\n';
    }
}