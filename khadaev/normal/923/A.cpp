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

vector<int> factor(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            ans.eb(i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1) ans.eb(n);
    return ans;
}

const int N = 1e6 + 10;
char pr[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int x2;
    cin >> x2;
    auto v = factor(x2);
    int mn = x2;
    for (int p : v) {
        int x = x2 - p + 1;
        setmax(x, p + 1);
        setmin(mn, x);
    }
    forn(i, 0, N) pr[i] = 1;
    forn(i, 2, N) if (pr[i]) {
        for (int j = 2 * i; j < N; j += i)
            pr[j] = 0;
    }
    int ans = INF;
    for (int i = 2; i < N; ++i) if (pr[i]) {
        int x1 = mn / i * i;
        if (x1 < mn) x1 += i;
        if (x1 > x2) continue;
        int x0 = x1 - i + 1;
        setmax(x0, i + 1);
        setmin(ans, x0);
    }
    cout << ans << '\n';
}