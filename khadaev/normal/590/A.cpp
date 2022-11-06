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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    vector<int> uns(n);
    forn(i, 1, n - 1)
        if (a[i] != a[i - 1] && a[i] != a[i + 1])
            uns[i] = 1;
    int ans = 0;
    forn(i, 0, n) if (uns[i]) {
        int j = i;
        while (uns[j]) ++j;
        int len = j - i;
        setmax(ans, (len + 1) / 2);
        if (len % 2) {
            forn(k, i, j) a[k] = a[j];
        } else {
            forn(k, i, i + len / 2)
                a[k] = a[i - 1];
            forn(k, i + len / 2, j)
                a[k] = a[j];
        }
        i = j;
    }
    cout << ans << '\n';
    forn(i, 0, n) cout << a[i] << ' ';
}