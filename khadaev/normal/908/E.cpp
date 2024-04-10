#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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

const int N = 1010;
ll binom[N][N];
ll part[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    binom[0][0] = 1;
    forn(i, 1, N) {
        binom[i][0] = 1;
        forn(j, 1, N) {
            binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
            binom[i][j] %= MOD;
        }
    }
    part[0] = 1;
    forn(i, 1, N) {
        fore(j, 1, i) {
            part[i] += part[i - j] * binom[i - 1][j - 1];
            part[i] %= MOD;
        }
    }
    int n, m;
    cin >> m >> n;
    vector<bitset<N>> s(n);
    forn(i, 0, n) {
        string in;
        cin >> in;
        forn(j, 0, m) if (in[j] == '1') s[i].set(j);
    }
    vector<int> color(m, -1);
    int cur = 0;
    ll ans = 1;
    forn(i, 0, m) {
        if (color[i] != -1) continue;
        bitset<N> here;
        here = ~here;
        forn(j, 0, n) {
            if (s[j][i]) here &= s[j];
            else here &= ~s[j];
        }
        int cnt = 0;
        forn(j, 0, m)
            if (here[j]) {
                color[j] = cur;
                ++cnt;
            }
        ++cur;
        ans *= part[cnt];
        ans %= MOD;
    }
    cout << ans << '\n';
}