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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, int>> seals;
    forn(i, 0, n) {
        int x, y;
        cin >> x >> y;
        seals.eb(x, y);
        seals.eb(y, x);
    }
    int ans = 0;
    forn(i, 0, 2 * n)
        forn(j, 0, i) {
            if (i % 2 == 1 && i == j + 1) continue;
            if (seals[i].fs > a || seals[j].fs > a || seals[i].sn > b || seals[j].sn > b) continue;
            if (seals[i].fs + seals[j].fs > a && seals[i].sn + seals[j].sn > b) continue;
            setmax(ans, seals[i].fs * seals[i].sn + seals[j].fs * seals[j].sn);
        }
    cout << ans << '\n';
}