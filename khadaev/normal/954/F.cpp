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

using matrix = vector<vector<ll>>;

matrix operator* (matrix a, matrix b) {
    int n = (int)a.size();
    matrix ans(n, vector<ll>(n));
    forn(i, 0, n)
        forn(j, 0, n)
            forn(k, 0, n)
                ans[i][k] += a[i][j] * b[j][k];
    forn(i, 0, n)
        forn(j, 0, n)
            ans[i][j] %= MOD;
    return ans;
}

vector<ll> operator*(matrix m, vector<ll> a) {
    int n = (int)a.size();
    vector<ll> ans(n);
    forn(i, 0, n)
        forn(j, 0, n)
            ans[i] += m[i][j] * a[j];
    forn(i, 0, n) ans[i] %= MOD;
    return ans;
}

matrix Id(int n) {
    matrix ans(n, vector<ll>(n));
    forn(i, 0, n) ans[i][i] = 1;
    return ans;
}

matrix Pow(matrix a, ll n) {
    matrix x = Id((int)a.size()), y = a;
    while (n) {
        if (n % 2) x = x * y;
        y = y * y;
        n /= 2;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    ll m;
    cin >> n >> m;
    vector<tuple<ll, int, int>> b;
    while (n--) {
        int a;
        ll l, r;
        cin >> a >> l >> r;
        --a, --l;
        b.eb(l, a, +1);
        b.eb(r, a, -1);
    }
    b.eb(m - 1, 0, 0);
    sort(all(b));
    vector<ll> cnt = {0, 1, 0};
    ll x = 0;
    vector<int> blocked(3, 0);
    int i = 0;
    while (i < (int)b.size()) {
        auto [l, a, sgn] = b[i];
        matrix mt(3, vector<ll>(3));
        forn(j, 0, 3)
            forn(k, 0, 3)
                if (!blocked[j] && !blocked[k] && abs(j - k) <= 1)
                    mt[k][j] = 1;
        cnt = Pow(mt, l - x - 1) * cnt;
        //cerr << cnt << '\n';
        x = l;
        vector<int> newBlocked = blocked;
        while (i < (int)b.size()) {
            auto [l0, a0, sgn0] = b[i];
            if (l0 != l) break;
            newBlocked[a0] += sgn0;
            ++i;
        }
        mt = matrix(3, vector<ll>(3, 0));
        forn(j, 0, 3)
            forn(k, 0, 3)
                if (!blocked[j] && !newBlocked[k] && abs(j - k) <= 1)
                    mt[k][j] = 1;
        //cerr << cnt << '\n';
        cnt = mt * cnt;
        //cerr << cnt << '\n';
        blocked = newBlocked;
        forn(j, 0, 3)
            if (blocked[j])
                assert(cnt[j] == 0);
    }
    cout << cnt[1] << '\n';
}