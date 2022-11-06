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

const int SZ = 10001;
using bs = bitset<SZ>;

const int N = 1 << 14;
vector<int> tree[2 * N];

void query(int l, int r, int val) {
    l += N, r += N;
    while (l < r) {
        if (l % 2) {
            tree[l++].eb(val);
        }
        if (r % 2) {
            tree[--r].eb(val);
        }
        l /= 2;
        r /= 2;
    }
}

bs ans;

void rec(int v, bs cur) {
    for (int x : tree[v]) {
        cur |= (cur << x);
    }
    if (v >= N) {
        ans |= cur;
        return;
    }
    rec(2 * v, cur);
    rec(2 * v + 1, cur);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, q;
    cin >> n >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        query(--l, r, x);
    }
    bs tmp;
    tmp.set(0);
    rec(1, tmp);
    vector<int> out;
    fore(i, 1, n)
        if (ans[i])
            out.eb(i);
    cout << out.size() << '\n' << out << '\n';
}