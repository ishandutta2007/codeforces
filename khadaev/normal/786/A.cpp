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

const int N = 7010;
int ans[2][N], k[2], s[2][N], deg[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, 0, 2) {
        cin >> k[i];
        forn(j, 0, k[i]) cin >> s[i][j];
    }
    forn(i, 0, 2) forn(j, 0, n) ans[i][j] = 2;
    forn(i, 0, 2) forn(j, 0, n) deg[i][j] = k[i];
    vector<pair<int, int>> wins, loses;
    loses.eb(0, 0);
    loses.eb(1, 0);
    while (!wins.empty() || !loses.empty()) {
        if (loses.empty()) {
            auto q = wins.back();
            wins.pop_back();
            int pl = q.fs, pos = q.sn;
            if (ans[pl][pos] != 2) continue;
            ans[pl][pos] = 0;
            forn(i, 0, k[1 - pl]) {
                int step = s[1 - pl][i];
                int x = pos - step;
                if (x < 0) x += n;
                --deg[1 - pl][x];
                if (deg[1 - pl][x] == 0)
                    loses.eb(1 - pl, x);
            }
        } else {
            auto q = loses.back();
            loses.pop_back();
            int pl = q.fs, pos = q.sn;
            if (ans[pl][pos] != 2) continue;
            ans[pl][pos] = 1;
            forn(i, 0, k[1 - pl]) {
                int step = s[1 - pl][i];
                int x = pos - step;
                if (x < 0) x += n;
                wins.eb(1 - pl, x);
            }
        }
    }
    forn(i, 0, 2) {
        forn(j, 1, n) {
            if (ans[i][j] == 0) cout << "Win ";
            else if (ans[i][j] == 1) cout << "Lose ";
            else cout << "Loop ";
        }
        cout << '\n';
    }
}