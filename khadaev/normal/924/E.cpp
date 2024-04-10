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

const int N = 10010;
const int SZ = N / 64 + 2;
ull sums[SZ], notAllGood[SZ];

void shiftOR(ull* from, ull* to, int k) {
    int res = k % 64;
    ford(i, 0, SZ) {
        int ix = i - k / 64;
        if (ix >= 0)
            to[i] |= from[ix] << res;
        --ix;
        if (res && ix >= 0)
            to[i] |= from[ix] >> (64 - res);
    }
}

int get(ull* s, int x) {
    return (s[x / 64] >> (x % 64)) & 1;
}

int lb(ull* s, int l) {
    int ix = l / 64;
    for (int i = l % 64; i < 64; ++i)
        if (s[ix] & (1ull << i))
            return 64 * ix + i;
    for (int i = ix + 1; i < SZ; ++i)
        if (s[i]) {
            for (int j = 0; j < 64; ++j)
                if (s[i] & (1 << j))
                    return 64 * i + j;
        }
    return 64 * SZ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> good, bad;
    vector<int> a(n), b(n);
    cin >> a >> b;
    forn(i, 0, n) {
        if (b[i]) good.eb(a[i]);
        else bad.eb(a[i]);
    }
    sort(all(good));
    sums[0] = 1;
    for (int x : bad)
        shiftOR(sums, sums, x);
    //memcpy(notAllGood, sums, sizeof sums);
    //forn(i, 0, 1000)
    //    if (get(sums, i))
    //        cerr << i << ' ';
    //return 0;
    int ans = 0;
    int k = (int)good.size();
    if (k == 0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> pref(k);
    pref[0] = good[0];
    forn(i, 1, k)
        pref[i] = pref[i - 1] + good[i];
    int goodSum = pref.back();
    while (!good.empty()) {
        int l0 = lb(sums, l);
        //cerr << l0 << '\n';
        int dist = r - l0;
        int cnt = int(upper_bound(all(pref), dist) - pref.begin()) + 1;
        if (dist < 0) cnt = 0;
        setmin(cnt, int(good.size()));
        //cerr << cnt << '\n';
        setmax(ans, cnt);
        //cerr << '\n';
        l0 = lb(notAllGood, l);
        //cerr << l0 << '\n';
        dist = r - l0;
        cnt = int(upper_bound(all(pref), dist) - pref.begin()) + 1;
        if (cnt > (int)good.size()) {
            cnt = (int)good.size() + 1;
        }
        if (dist < 0) cnt = 0;
        //cerr << cnt << '\n';
        setmax(ans, cnt);

        shiftOR(notAllGood, notAllGood, good.back());
        shiftOR(sums, notAllGood, 0);
        shiftOR(sums, sums, good.back());
        goodSum -= good.back();
        good.pop_back();
        //cerr << '\n';
    } 
    {
        int l0 = lb(notAllGood, l);
        //cerr << l0 << '\n';
        int dist = r - l0;
        int cnt = int(upper_bound(all(pref), dist) - pref.begin()) + 1;
        if (cnt > (int)good.size()) {
            cnt = (int)good.size() + 1;
        }
        if (dist < 0) cnt = 0;
        //cerr << cnt << '\n';
        setmax(ans, cnt);

    }
    cout << ans << '\n';
}