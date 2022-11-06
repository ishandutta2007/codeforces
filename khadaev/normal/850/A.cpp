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

const int N = 1010;
int pr[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    //n = 1000;
    vector<vector<int>> a(n, vector<int>(5));
    forn(i, 0, n) forn(j, 0, 5)
        //a[i][j] = rand() % 10 - 10;
        cin >> a[i][j];
    forn(i, 0, n) forn(j, 0, n) forn(k, 0, 5) pr[i][j] += a[i][k] * a[j][k];
    vector<int> ans;
    forn(i, 0, n) {
        bool ok = true;
        forn(j, 0, n) {
            if (j == i) continue;
            forn(k, 0, j) {
                if (k == i) continue;
                if (pr[j][k] + pr[i][i] > pr[i][j] + pr[i][k])
                    ok = false;
            }
        }
        if (ok) ans.eb(i);
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << 1 + x << ' ';
}