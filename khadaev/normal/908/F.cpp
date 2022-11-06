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

int get(vector<int>& xs, int prv, int nxt, int& it) {
    if (it == xs.size() || xs[it] > nxt) return nxt - prv;
    int lx = xs[it];
    int gap = xs[it] - prv;
    while (++it < xs.size() && xs[it] < nxt) {
        setmax(gap, xs[it] - lx);
        lx = xs[it];
    }
    setmax(gap, nxt - lx);
    return gap;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vector<int> green, red, blue;
    forn(i, 0, n) {
        int x;
        char c;
        cin >> x >> c;
        if (c == 'G') green.eb(x);
        else if (c == 'R') red.eb(x);
        else blue.eb(x);
    }
    int ans = 0;
    if (green.empty()) {
        if (!blue.empty()) ans += *blue.rbegin() - *blue.begin();
        if (!red.empty()) ans += *red.rbegin() - *red.begin();
        cout << ans << '\n';
        return 0;
    }
    if (!blue.empty()) {
        if (*blue.begin() < *green.begin()) ans += *green.begin() - *blue.begin();
        if (*blue.rbegin() > *green.rbegin()) ans -= *green.rbegin() - *blue.rbegin();
    }
    if (!red.empty()) {
        if (*red.begin() < *green.begin()) ans += *green.begin() - *red.begin();
        if (*red.rbegin() > *green.rbegin()) ans -= *green.rbegin() - *red.rbegin();
    }
    int sz = green.size();
    int b = 0, r = 0;
    while (b < blue.size() && blue[b] < green[0]) ++b;
    while (r < red.size() && red[r] < green[0]) ++r;
    forn(i, 1, sz) {
        int dist = green[i] - green[i - 1];
        int bgap = get(blue, green[i - 1], green[i], b), rgap = get(red, green[i - 1], green[i], r);
        int here = min(2 * dist, 3 * dist - bgap - rgap);
        ans += here;
    }
    cout << ans << '\n';
}