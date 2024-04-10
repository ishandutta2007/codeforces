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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    forn(i, 0, n) {
        cin >> a[i];
        if (a[i] == 1) ++ones;
    }
    if (ones) {
        cout << n - ones << '\n';
        return 0;
    }
    int len = INF;
    forn(i, 0, n) {
        int x = a[i];
        forn(j, i + 1, n) {
            x = __gcd(x, a[j]);
            if (x == 1) {
                setmin(len, j - i + 1);
                break;
            }
        }
    }
    if (len == INF) cout << -1 << '\n';
    else cout << (n - 1) + (len - 1) << '\n';
}