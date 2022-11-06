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
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> g(n), p(n), t(n);
    map<int, vector<int>> gr;
    forn(i, 0, n) {
        cin >> g[i] >> p[i] >> t[i];
        gr[t[i] - p[i]].eb(i);
    }
    vector<int> xans(n), yans(n);
    for (auto _ : gr) {
        vector<int> nw = _.sn;
        int k = nw.size();
        vector<int> xs, ys;
        for (int i : nw) {
            if (g[i] == 1) xs.eb(i);
            else ys.eb(i);
        }
        sort(all(xs), [&](int i, int j) {
                return p[i] > p[j];
                });
        sort(all(ys), [&](int i, int j) {
                return p[i] < p[j];
                });
        vector<int> or1 = xs, or2 = ys;
        for (int i : ys) or1.eb(i);
        for (int i : xs) or2.eb(i);
        forn(i, 0, k) {
            int from = or1[i], to = or2[i];
            if (g[to] == 1) {
                xans[from] = p[to];
                yans[from] = h;
            } else {
                xans[from] = w;
                yans[from] = p[to];
            }
        }
    }
    forn(i, 0, n) cout << xans[i] << ' ' << yans[i] << '\n';
}