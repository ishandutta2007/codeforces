#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
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

const int N = 1e5 + 10;

vector<int> e[N];
vector<int> w[N];
int ans[N];

void fail() {
    cout << "No\n";
    exit(0);
}

void Set(int pos, int val) {
    if (ans[pos] == val) return;
    if (ans[pos] != -1) fail();
    ans[pos] = val;
}

void dfs(int i) {
    for (int j : e[i]) {
        if (ans[j] == 0) fail();
        if (ans[j] == -1) {
            ans[j] = 1;
            dfs(j);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    memset(ans, -1, sizeof ans);
    int n, m;
    cin >> n >> m;
    forn(i, 0, n) {
        int l;
        cin >> l;
        w[i].resize(l);
        forn(j, 0, l) cin >> w[i][j];
    }
    forn(i, 0, n - 1) {
        int j = 0;
        while (j < w[i].size() && j < w[i + 1].size() && w[i][j] == w[i + 1][j])
            ++j;
        if (j == w[i].size())
            continue;
        if (j == w[i + 1].size())
            fail();
        if (w[i][j] < w[i + 1][j])
            e[w[i + 1][j]].eb(w[i][j]);
        else {
            Set(w[i][j], 1);
            Set(w[i + 1][j], 0);
        }
    }
    fore(i, 1, m) if (ans[i] == 1) dfs(i);
    cout << "Yes\n";
    vector<int> out;
    fore(i, 1, m) if (ans[i] == 1) out.eb(i);
    cout << out.size() << '\n';
    for (int x : out) cout << x << ' ';
}