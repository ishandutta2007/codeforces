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

const int N = 800;
ll binom[N][N];
ll pw[11][N];
ll ones[N];

void pre() {
    binom[0][0] = 1;
    forn(i, 1, N) {
        binom[i][0] = 1;
        forn(j, 1, N) {
            binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
            binom[i][j] %= MOD;
        }
    }
    fore(i, 0, 10) {
        pw[i][0] = 1;
        forn(j, 1, N) pw[i][j] = i * pw[i][j - 1] % MOD;
    }
    forn(i, 1, N) ones[i] = (ones[i - 1] + pw[10][i - 1]) % MOD;
}

ll solve(vector<int>& fixed, int free) {
    //cerr << "debug\n";
    //cerr << free << '\n';
    //trace(fixed);
    ll ans = 0;
    ll have = 0;
    ford(i, 1, 10) {
        have += fixed[i];
        fore(j, 0, free) {
            ll here = binom[free][j] * pw[10 - i][j] % MOD;
            (here *= pw[i][free - j]) %= MOD;
            (here *= ones[j + have]) %= MOD;
            ans += here;
            if (ans >= MOD) ans -= MOD;
        }
    }
    //cerr << ans << '\n';
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    pre();
    string X;
    cin >> X;
    //X = "1";
    //forn(i, 0, 700) X += "0";
    int n = X.size();
    ll ans = 0;
    forn(i, 1, n) {
        forn(d, 1, 10) {
            vector<int> fixed(10, 0);
            fixed[d] = 1;
            ans += solve(fixed, i - 1);
        }
    }
    vector<int> fixed(10, 0);
    forn(j, 1, X[0] - '0') {
        fixed[j] = 1;
        ans += solve(fixed, n - 1);
        fixed[j] = 0;
    }
    fixed[X[0] - '0'] = 1;
    forn(i, 1, n) {
        forn(j, 0, X[i] - '0') {
            ++fixed[j];
            ans += solve(fixed, n - i - 1);
            --fixed[j];
        }
        ++fixed[X[i] - '0'];
    }
    ans += solve(fixed, 0);
    cout << ans % MOD << '\n';
}