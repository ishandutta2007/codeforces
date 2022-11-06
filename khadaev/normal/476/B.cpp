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

const int N = 21;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int d1 = 0, d2 = 0, q = 0;
    forn(i, 0, n) {
        if (s1[i] == '+') ++d1;
        else --d1;
    }
    forn(i, 0, n) {
        if (s2[i] == '+') ++d2;
        else if (s2[i] == '-') --d2;
        else ++q;
    }
    int l = (d2 - d1 + q) / 2;
    if (l < 0 || l > q) return cout << "0\n", 0;
    ld p = 1.0;
    fore(i, 1, l) p /= i;
    fore(i, 1, q - l) p /= i;
    fore(i, 1, q) p *= i;
    forn(i, 0, q) p /= 2.0;
    cout << fixed << setprecision(10) << p << '\n';
}