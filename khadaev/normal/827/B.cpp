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
vector<int> e[N];

void add(int i, int j) {
    e[i].eb(j);
    e[j].eb(i);
}

int h[N];
void dfs(int i, int p) {
    if (p == -1) h[i] = 0;
    else h[i] = 1 + h[p];
    for (int j : e[i]) if (j != p) dfs(j, i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int nxt = k;
    forn(i, 0, n - 1) {
        add(i, nxt);
        ++nxt;
        setmin(nxt, n - 1);
    }
    dfs(0, -1);
    int mx = 0;
    forn(i, 0, n) if (h[i] > h[mx]) mx = i;
    dfs(mx, -1);
    int ans = 0;
    forn(i, 0, n) setmax(ans, h[i]);
    cout << ans << '\n';
    forn(i, 0, n) for (int j : e[i]) if (i < j) cout << 1 + i << ' ' << 1 + j << '\n';
}