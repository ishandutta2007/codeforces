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

using T = tuple<int, int, int>;
bool eq(T x, T y) {
    return get<0>(x) == get<0>(y) && get<1>(y) == get<1>(x);
}
int pw[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    pw[0] = 1;
    forn(i, 1, 10) pw[i] = 10 * pw[i - 1];
    cin >> n;
    vector<tuple<int, int, int>> a;
    forn(i, 0, n) {
        vector<pair<int, int>> sub;
        int x;
        cin >> x;
        int len1 = 9;
        while (len1) {
            int len2 = len1;
            int y = x;
            while (len2) {
                sub.eb(y, len2);
                --len2;
                y /= 10;
            }
            --len1;
            x %= pw[len1];
        }
        sort(all(sub));
        forn(j, 0, sub.size())
            if (j == 0 || sub[j] != sub[j - 1])
                a.eb(sub[j].sn, sub[j].fs, i);
    }
    sort(all(a));
    vector<pair<int, int>> ans(n, {-1, -1});
    int sz = a.size();
    forn(i, 0, sz) {
        if (i && eq(a[i], a[i - 1])) continue;
        if (i < sz - 1 && eq(a[i], a[i + 1])) continue;
        int x, y, z;
        tie(y, x, z) = a[i];
        if (ans[z] == make_pair(-1, -1)) {
            ans[z] = {x, y};
        }
    }
    forn(i, 0, n) {
        //cerr << ans[i].fs << ' ' << ans[i].sn << '\n';
        vector<char> out;
        int x = ans[i].fs;
        while (x) {
            out.eb(x % 10);
            x /= 10;
        }
        forn(j, 0, int(ans[i].sn - out.size())) cout << '0';
        if (ans[i].fs) cout << ans[i].fs;
        cout << '\n';
    }
}