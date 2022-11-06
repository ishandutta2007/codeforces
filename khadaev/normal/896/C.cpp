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

void test(int n) {
    vector<int> a(n);
    forn(i, 0, n)
        a[i] = rand();
    forn(i, 0, 1000) {
        set<int> vals(all(a));
        cout << vals.size() << '\n';
        int l = rand() % n, r = rand() % n;
        if (l > r) swap(l, r);
        int x = rand();
        fore(j, l, r)
            a[j] = x;
    }
}

ll seed;

int rnd() {
    ll ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return (int)ret;
}

ll Pow(ll a, ll b, ll mod) {
    ll x = 1, y = a % mod;
    while (b) {
        if (b & 1) (x *= y) %= mod;
        (y *= y) %= mod;
        b /= 2;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    //test(100000);
    int n, m, vmax;
    cin >> n >> m >> seed >> vmax;
    vector<pair<ll, int>> a(n);
    for (auto& p : a) {
        p.fs = rnd() % vmax + 1;
        p.sn = 1;
    }
    while (m--) {
        int op = rnd() % 4;
        int l = rnd() % n;
        int r = rnd() % n;
        if (l > r) swap(l, r);
        ++r;
        vector<pair<ll, int>> b;
        //for (auto p : a) {
        //    cerr << p.fs << ' ' << p.sn << "   ";
        //}
        //cerr << '\n';
        //cerr << "q: " << op << ' ' << l << ' ' << r << '\n';
        if (op == 0) {
            int x = rnd() % vmax + 1;
            int len = 0;
            for (auto p : a) {
                if (len < l) {
                    b.eb(p.fs, min(l, len + p.sn) - len);
                }
                int common = min(len + p.sn, r) - max(len, l);
                if (common > 0) {
                    b.eb(p.fs + x, common);
                }
                if (len + p.sn > r) {
                    b.eb(p.fs, len + p.sn - max(r, len));
                }
                len += p.sn;
            }
            a.swap(b);
        } else if (op == 1) {
            int x = rnd() % vmax + 1;
            int len = 0;
            bool done = false;
            for (auto p : a) {
                if (len < l) {
                    b.eb(p.fs, min(l, len + p.sn) - len);
                }
                int common = min(len + p.sn, r) - max(len, l);
                if (common > 0) {
                    if (!done) {
                        b.eb(x, r - l);
                        done = true;
                    }
                }
                if (len + p.sn > r) {
                    b.eb(p.fs, len + p.sn - max(r, len));
                }
                len += p.sn;
            }
            a.swap(b);
        } else if (op == 2) {
            int x = rnd() % (r - l);
            vector<pair<ll, int>> here;
            int len = 0;
            for (auto p : a) {
                int common = min(len + p.sn, r) - max(len, l);
                if (common > 0) {
                    here.eb(p.fs, common);
                }
                len += p.sn;
            }
            sort(all(here));
            for (auto p : here) {
                if (x < p.sn) {
                    cout << p.fs << '\n';
                    break;
                }
                x -= p.sn;
            }
        } else {
            int x = rnd() % vmax + 1;
            int y = rnd() % vmax + 1;
            int len = 0;
            ll ans = 0;
            for (auto p : a) {
                int common = min(len + p.sn, r) - max(len, l);
                if (common > 0) {
                    //cerr << "cnt: " << cnt << '\n';
                    ans += common * Pow(p.fs, x, y);
                    ans %= y;
                }
                len += p.sn;
            }
            cout << ans << '\n';
        }
    }
}