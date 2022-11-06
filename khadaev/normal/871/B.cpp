#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
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

int get(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int x;
    cin >> x;
    return x;
}

bool is_perm(vector<int> a) {
    int n = a.size();
    vector<int> cnt(n);
    for (int x : a) {
        if (x < 0 || x >= n)
            return false;
        if (cnt[x]) return false;
        ++cnt[x];
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    forn(i, 0, n) a[i] = get(0, i);
    b[0] = a[0];
    forn(i, 1, n) b[i] = get(i, 0);
    vector<int> ans;
    int cnt = 0;
    forn(x, 0, n) {
        vector<int> p1(n), p2(n);
        forn(i, 0, n)
            p2[i] = x ^ a[i];
        forn(i, 0, n)
            p1[i] = p2[0] ^ b[i];
        bool ok = is_perm(p1) && is_perm(p2);
        for (int i = 0; i < n && ok; ++i)
            if (p1[p2[i]] != i) ok = false;
        if (ok) {
            ++cnt;
            ans = p1;
        }
    }
    cout << "!\n";
    cout << cnt << '\n';
    forn(i, 0, n) cout << ans[i] << ' ';
    cout << endl;
}