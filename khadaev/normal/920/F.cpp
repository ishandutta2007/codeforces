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

const int A = 1e6 + 10, N = 1 << 19;
int d[A];

int mx[2 * N];
ll sum[2 * N];

void relax(int v) {
    sum[v] = sum[2 * v] + sum[2 * v + 1];
    mx[v] = max(mx[2 * v], mx[2 * v + 1]);
}

void _upd(int v, int l, int r, int lb, int rb) {
    if (lb >= r || rb <= l) return;
    if (mx[v] <= 2) return;
    if (v >= N) {
        sum[v] = d[sum[v]];
        mx[v] = (int)sum[v];
        return;
    }
    int mb = (lb + rb) / 2;
    _upd(2 * v, l, r, lb, mb);
    _upd(2 * v + 1, l, r, mb, rb);
    relax(v);
}

void upd(int l, int r) {
    _upd(1, l, r, 0, N);
}

ll get(int l, int r) {
    ll ans = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l % 2) ans += sum[l++];
        if (r % 2) ans += sum[--r];
    }
    return ans;
}
//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, q;
    cin >> n >> q;
    forn(i, 1, A)
        for (int j = i; j < A; j += i)
            ++d[j];
    forn(i, 0, n) {
        cin >> mx[i + N];
        sum[i + N] = mx[i + N];
    }
    ford(i, 1, N) relax(i);
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l;
        if (t == 1) upd(l, r);
        else cout << get(l, r) << ' ';
    }
}