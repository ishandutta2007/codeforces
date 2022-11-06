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
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> a(n);
    int l = 0, r = n - 1;
    while (l <= r) {
        int p;
        cin >> p;
        if (p <= c / 2) {
            int l1 = l;
            while (l1 > 0 && p < a[l1 - 1])
                --l1;
            cout << 1 + l1 << endl;
            a[l1] = p;
            if (a[l])
                ++l;
        } else {
            int r1 = r;
            while (r1 < n - 1 && p > a[r1 + 1])
                ++r1;
            cout << 1 + r1 << endl;
            a[r1] = p;
            if (a[r])
                --r;
        }
    }
}