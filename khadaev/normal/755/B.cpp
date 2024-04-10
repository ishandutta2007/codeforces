#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    set<string> common;
    forn(i, 0, n) {
        string s;
        cin >> s;
        common.insert(s);
    }
    int cnt = 0;
    forn(i, 0, m) {
        string s;
        cin >> s;
        cnt += common.count(s);
    }
    n -= cnt;
    m -= cnt;
    if (cnt % 2) {
        cout << (n >= m ? "YES\n" : "NO\n");
    } else 
        cout << (n > m ? "YES\n" : "NO\n");
}