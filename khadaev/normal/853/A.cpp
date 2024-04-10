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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    forn(i, 0, n) cin >> c[i];
    vector<int> ix(n);
    forn(i, 0, n) ix[i] = i;
    sort(all(ix), [&](int i, int j) {
                return c[i] > c[j];
                });
    set<int> free;
    forn(i, k, k + n) free.insert(i);
    vector<int> pos(n);
    ll ans = 0;
    for (int i : ix) {
        auto it = free.lower_bound(i);
        assert(it != free.end());
        pos[i] = *it;
        ans += 1ll * c[i] * (*it - i);
        free.erase(it);
    }
    cout << ans << '\n';
    forn(i, 0, n) cout << 1 + pos[i] << ' ';
}