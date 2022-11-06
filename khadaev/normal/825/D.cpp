#include <bits/stdc++.h>
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

const int N = 1e6 + 10;
int cnts[256], cntt[256], add[256];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int n = s.length(), x = t.length();
    forn(i, 0, n) ++cnts[s[i]];
    forn(i, 0, x) ++cntt[t[i]];
    ll l = 0, r = N;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        ll need = 0;
        for (char c = 'a'; c <= 'z'; ++c)
            need += max(0ll, m * cntt[c] - cnts[c]);
        if (need <= cnts['?'])
            l = m;
        else
            r = m;
    }
    for (char c = 'a'; c <= 'z'; ++c)
        add[c] = max(0ll, l * cntt[c] - cnts[c]);
    char it = 'a';
    forn(i, 0, n) {
        if (s[i] != '?') continue;
        while (it < 'z' && add[it] == 0) ++it;
        s[i] = it;
        --add[it];
    }
    cout << s << '\n';
}