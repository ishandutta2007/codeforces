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

const int N = 51;
char a[N][N];

void add(vector<pair<int, int>> &ans, int i, int j) {
    ans.eb(i, j);
    if (a[i][j] == 'L') {
        a[i][j] = 'U';
        a[i][j + 1] = 'U';
        a[i + 1][j] = 'D';
        a[i + 1][j + 1] = 'D';
    } else if (a[i][j] == 'U') {
        a[i][j] = 'L';
        a[i][j + 1] = 'R';
        a[i + 1][j] = 'L';
        a[i + 1][j + 1] = 'R';
    } else assert(false);
}

int n, m;
vector<pair<int, int>> solve() {
    bool rotate = false;
    vector<pair<int, int>> ans;
    if (m % 2) {
        swap(n, m);
        rotate = true;
        forn(i, 0, N) forn(j, 0, i) swap(a[i][j], a[j][i]);
        forn(i, 0, n) forn(j, 0, m) {
            if (a[i][j] == 'L') a[i][j] = 'U';
            else if (a[i][j] == 'U') a[i][j] = 'L';
            else if (a[i][j] == 'R') a[i][j] = 'D';
            else a[i][j] = 'R';
        }
    }

    forn(i, 0, n) {
        for (int j = 0; j < m; j += 2) {
            for (int k = 0; ; ++k) {
                if (a[i + k][j + k] == 'L') {
                    ford(l, 0, k) {
                        add(ans, i + l, j + l + 1);
                        add(ans, i + l, j + l);
                    }
                    break;
                }
                if (a[i + k][j + k + 1] == 'U') {
                    add(ans, i + k, j + k);
                    ford(l, 0, k) {
                        add(ans, i + l, j + l + 1);
                        add(ans, i + l, j + l);
                    }
                    break;
                }
            }
        }
    }


    if (rotate) {
        swap(n, m);
        int k = ans.size();
        forn(i, 0, k) ans[i] = {ans[i].sn, ans[i].fs};
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    forn(i, 0, n) cin >> a[i];
    auto a1 = solve();
    forn(i, 0, n) cin >> a[i];
    auto a2 = solve();
    reverse(all(a2));
    cout << a1.size() + a2.size() << '\n';
    for (auto p : a1) cout << 1 + p.fs << ' ' << 1 + p.sn << '\n';
    for (auto p : a2) cout << 1 + p.fs << ' ' << 1 + p.sn << '\n';
}