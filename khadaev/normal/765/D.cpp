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
    cin >> n;
    vector<int> f(n);
    forn(i, 0, n) {
        cin >> f[i];
        --f[i];
    }
    forn(i, 0, n) if (f[f[i]] != f[i]) {
        cout << "-1\n";
        return 0;
    }
    map<int, int> ix;
    int j = -1;
    forn(i, 0, n) if (f[i] == i) ix[i] = ++j;
    cout << ix.size() << '\n';
    forn(i, 0, n) cout << ix[f[i]] + 1 << ' ';
    cout << '\n';
    forn(i, 0, n) if (f[i] == i) cout << i + 1 << ' ';
    cout << '\n';
}