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

const int B = 30;
const int LOG = 18;
const int N = 1 << LOG;
int sp[LOG][N];
int lg2[N];

int get(int l, int r) {
    if (l == r) return -1;
    int len = lg2[r - l];
    return max(sp[len][l], sp[len][r - (1 << len)]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) sp[0][i] = a[i];
    forn(i, 1, LOG) forn(j, 0, 1 << LOG) {
        if (j + (1 << i) == (1 << LOG)) break;
        sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
    }
    forn(i, 0, LOG)
        forn(j, 1 << i, 1 << (i + 1))
            lg2[j] = i;
    vector<int> nxt(B, 0);
    ll ans = 0;
    forn(i, 0, n) {
        forn(j, 0, B) {
            if (nxt[j] <= i) nxt[j] = i + 1;
            while (nxt[j] < n && (0 == (a[nxt[j]] & (1 << j))))
                ++nxt[j];
        }
        //trace(nxt);
        vector<pair<int, int>> st;
        forn(j, 0, B) {
            if (a[i] & (1 << j)) continue;
            if (nxt[j] == n) continue;
            st.eb(nxt[j], j);
        }
        sort(all(st));
        int val = a[i];
        int pr = i;
        for (auto p : st) {
            if (p.fs == pr) {
                val |= (1 << p.sn);
                continue;
            }
            int l = pr, r = p.fs + 1;
            while (l < r - 1) {
                int m = (l + r) / 2;
                if (get(l, m) < val)
                    l = m;
                else
                    r = m;
            }
            ans += l - pr;
            pr = p.fs;
            val |= (1 << p.sn);
        }
        {
            int l = pr, r = n + 1;
            while (l < r - 1) {
                int m = (l + r) / 2;
                if (get(l, m) < val)
                    l = m;
                else
                    r = m;
            }
            ans += l - pr;
        }
    }
    cout << ans << '\n';
}