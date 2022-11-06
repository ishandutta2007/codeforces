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

const int LEN = 14;
const int N = 222;
bitset<1 << LEN> sets[N][LEN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vector<string> s(n);
    forn(i, 0, n) cin >> s[i];
    vector<string> pref = s, suff = s;
    forn(i, 1, LEN) {
        forn(ix, 0, n) {
            forn(j, 0, int(s[ix].size()) - i + 1) {
                int msk = 0;
                forn(k, 0, i) {
                    msk *= 2;
                    msk += s[ix][j + k] - '0';
                }
                sets[ix][i].set(msk);
            }
        }
    }
    int m;
    cin >> m;
    int ix = n;
    while (m--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        string new_pref = pref[a].size() >= LEN ? pref[a] : pref[a] + pref[b];
        if (new_pref.size() > LEN) new_pref = new_pref.substr(0, LEN);
        string new_suff = suff[b].size() >= LEN ? suff[b] : suff[a] + suff[b];
        if (new_suff.size() > LEN) new_suff = new_suff.substr(new_suff.size() - LEN, LEN);
        pref.eb(new_pref);
        suff.eb(new_suff);
        forn(len, 1, LEN) {
            sets[ix][len] = sets[a][len] | sets[b][len];
            forn(l, 1, len) {
                int r = len - l;
                if (l > suff[a].size()) continue;
                if (r > pref[b].size()) continue;
                int msk = 0;
                forn(i, 0, l) {
                    msk *= 2;
                    msk += suff[a][suff[a].size() - l + i] - '0';
                }
                forn(i, 0, r) {
                    msk *= 2;
                    msk += pref[b][i] - '0';
                }
                sets[ix][len].set(msk);
            }
        }
        forn(i, 1, LEN) if (sets[ix][i].count() != (1 << i)) {
            cout << i - 1 << '\n';
            //cout << sets[ix][i].count() << '\n';
            break;
        }
        ++ix;
    }

}