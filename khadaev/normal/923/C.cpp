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

const int N = 3e5 + 10;
const int SZ = N * 31;

int go[SZ][2];
int cnt[SZ];
int nxt = 1;

void add(int x) {
    int pos = 0;
    ford(i, 0, 30) {
        ++cnt[pos];
        int& to = go[pos][(x >> i) & 1];
        if (to == -1) to = nxt++;
        pos = to;
    }
    ++cnt[pos];
}

int findMin(int x) {
    int pos = 0;
    int res = 0;
    ford(i, 0, 30) {
        int bit = (x >> i) & 1;
        int to = go[pos][bit];
        if (to == -1 || cnt[to] == 0) {
            bit ^= 1;
            to = go[pos][bit];
        }
        res += bit << i;
        --cnt[pos];
        pos = to;
    }
    --cnt[pos];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    memset(go, -1, sizeof go);
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    cin >> a >> p;
    for (int x : p) add(x);
    for (int x : a) cout << (x ^ findMin(x)) << ' ';
}