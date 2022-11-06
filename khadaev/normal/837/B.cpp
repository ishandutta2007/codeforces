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

string a[111];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<char> colors = {'B', 'G', 'R'};
    int n, m;
    cin >> n >> m;
    forn(i, 0, n) cin >> a[i];
    if (n % 3 == 0) {
        vector<char> in;
        forn(i, 0, 3) {
            bool ok = true;
            char c = a[i * n / 3][0];
            forn(j, 0, n / 3) forn(k, 0, m)
                if (a[i * n / 3 + j][k] != c) ok = false;
            if (ok) in.eb(c);
        }
        sort(all(in));
        if (in == colors) {
            cout << "YES\n";
            return 0;
        }
    }
    if (m % 3 == 0) {
        vector<char> in;
        forn(i, 0, 3) {
            bool ok = true;
            char c = a[0][i * m / 3];
            forn(j, 0, m / 3) forn(k, 0, n)
                if (a[k][i * m / 3 + j] != c) ok = false;
            if (ok) in.eb(c);
        }
        sort(all(in));
        if (in == colors) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}