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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    //n = 1e5;
    vector<int> a(n);
    cin >> a;
    //forn(i, 0, n) a[i] = rand() % 1000 - 500;
    int mn = 0;
    forn(i, 0, n) setmin(mn, a[i]);
    forn(i, 0, n) a[i] -= mn;
    int add = -mn;
    vector<vector<int>> bit(21);
    vector<int> here(21);
    fore(i, 0, 20) {
        bit[i].resize(1 << (i + 1));
        for (int x : a) {
            if (x & (1 << i))
                ++here[i];
            int y = x & ((1 << 22) - (1 << (i + 1)));
            int st = (/*y == x ? 0 : */((1 << i) - x + y));
            if (st < 0) st += (1 << (i + 1));
            int fn = st ^ (1 << i);
            //cerr << i << ' ' << st << ' ' << fn << '\n';
            ++bit[i][st];
            --bit[i][fn];
        }
    }
    /*
    fore(i, 1, add) {
        fore(j, 0, 20) {
            here[j] += bit[j][i % (1 << (j + 1))];
        }
    }
    */
    int OR = 0;
    forn(j, 0, 20)
        if (here[j])
            OR |= (1 << j);
    int ans = __builtin_popcount(OR | add);
    int toAdd = add;
    int optOr = OR | add;
    int mx = 0;
    for (int x : a)
        setmax(mx, x);
    while (++add <= (1 << 20)) {
        ++mx;
        if (mx >= (1 << 20)) break;
        forn(j, 0, 20)
            here[j] += bit[j][(add + mn) % (1 << (j + 1))];
        OR = 0;
        forn(j, 0, 20)
            if (here[j])
                OR |= (1 << j);
        /*
        int testOr = 0;
        for (int x : a)
            testOr |= (x + add + mn);
        if (OR != testOr) {
            cerr << add << '\n';
            cerr << "error\n";
            return 0;
        }
        */
        int cur = __builtin_popcount(OR | add);
        if (cur < ans) {
            ans = cur;
            toAdd = add;
            optOr = OR | add;
        }
    }
    //cout << ans << ' ' << toAdd  << ' ' << optOr << '\n';
    cout << ans << '\n';
    fore(i, 0, 20) {
        if (optOr & (1 << i)) {
            if (toAdd & (1 << i)) cout << '-';
            cout << (1 << i) << ' ';
        }
    }
}