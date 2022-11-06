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

const int B = 22;
const int N = 1 << B;
char a[N], u1[N], u2[N];

void dfs2(int i);

void dfs1(int i) {
    if (u1[i]) return;
    u1[i] = 1;
    dfs2((N - 1) ^ i);
}

void dfs2(int i) {
    if (u2[i]) return;
    u2[i] = 1;
    if (a[i]) dfs1(i);
    forn(j, 0, B)
        if (i & (1 << j))
            dfs2(i ^ (1 << j));
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x;
        scanf("%d", &x);
        a[x] = 1;
    }
    int ans = 0;
    forn(i, 0, 1 << n)
        if (a[i] && !u1[i]) {
            ++ans;
            dfs1(i);
        }
    cout << ans << '\n';
}