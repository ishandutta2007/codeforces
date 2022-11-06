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
    int n;
    string s, t;
    cin >> n >> s >> t;
    int d = 0;
    forn(i, 0, n) d += s[i] != t[i];
    set<pair<int, int>> ps;
    forn(i, 0, n) ps.emplace(s[i] - 'a', t[i] - 'a');
    forn(i, 0, 26) forn(j, 0, 26) if (i != j && ps.find({i, j}) != ps.end() && ps.find({j, i}) != ps.end()) {
        cout << d - 2 << '\n';
        int p1, p2;
        forn(p, 0, n) if (s[p] - 'a' == i && t[p] - 'a' == j) p1 = p;
        forn(p, 0, n) if (s[p] - 'a' == j && t[p] - 'a' == i) p2 = p;
        ++p1, ++p2;
        cout << p1 << ' ' << p2 << '\n';
        return 0;
    }
    set<char> ls, lt;
    forn(i, 0, n) if (s[i] != t[i]) {
        ls.insert(s[i] - 'a');
        lt.insert(t[i] - 'a');
    }
    forn(i, 0, 26) if (ls.find(i) != ls.end() && lt.find(i) != lt.end()) {
        cout << d - 1 << '\n';
        int p1, p2;
        forn(p, 0, n) if (s[p] - 'a' == i && t[p] - 'a' != i) p1 = p;
        forn(p, 0, n) if (t[p] - 'a' == i && s[p] - 'a' != i) p2 = p;
        ++p1, ++p2;
        cout << p1 << ' ' << p2 << '\n';
        return 0;
    }
    cout << d << '\n';
    cout << "-1 -1\n";
    return 0;
}