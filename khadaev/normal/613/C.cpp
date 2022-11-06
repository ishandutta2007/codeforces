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
    vector<pair<int, char>> odd, even;
    char c = 'a';
    forn(i, 0, n) {
        int a;
        cin >> a;
        if (a % 2) odd.eb(a, c);
        else even.eb(a, c);
        ++c;
    }
    if (odd.size() >= 2) {
        cout << "0\n";
        for (auto j : odd) {
            forn(k, 0, j.fs) cout << j.sn;
        }
        for (auto j : even) {
            forn(k, 0, j.fs) cout << j.sn;
        }
        cout << '\n';
        return 0;
    }
    int g = 0;
    int sz = even.size();
    for (auto j : odd) g = __gcd(g, j.fs);
    for (auto j : even) g = __gcd(g, j.fs);
    cout << g << '\n';
    if (odd.size() == 1) {
        forn(it, 0, g) {
            cout << odd[0].sn;
            forn(i, 0, sz)
                forn(j, 0, even[i].fs / g / 2)
                    cout << even[i].sn;
            forn(j, 0, (odd[0].fs - g) / g)
                cout << odd[0].sn;
            forn(i, 0, sz)
                forn(j, 0, even[sz - 1 - i].fs / g / 2)
                    cout << even[sz - 1 - i].sn;
        }
        cout << '\n';
        return 0;
    }
    if (odd.size() == 0) {
        forn(it, 0, g / 2) {
            forn(i, 0, sz)
                forn(j, 0, even[i].fs / g)
                    cout << even[i].sn;
            forn(i, 0, sz)
                forn(j, 0, even[sz - 1 - i].fs / g)
                    cout << even[sz - 1 - i].sn;
        }
        cout << '\n';
        return 0;
    }
}