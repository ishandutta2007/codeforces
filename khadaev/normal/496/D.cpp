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

const int N = 1e5 + 10;
int a[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, 0, n) {
        int v;
        cin >> v;
        if (i) {
            a[0][i] = a[0][i - 1];
            a[1][i] = a[1][i - 1];
        }
        a[v - 1][i]++;
    }
    vector<pair<int, int>> ans;
    fore(t, 1, n) {
        bool ok = true;
        int rs[2];
        forn(i, 0, 2) rs[i] = 0;
        int cur = 0;
        while (1) {
            int l = cur - 1, r = n;
            while (l < r - 1) {
                int m = (l + r) / 2;
                assert(m != n);
                int v[2];
                forn(i, 0, 2) v[i] = a[i][m] - (cur ? a[i][cur - 1] : 0);
                if (v[0] >= t || v[1] >= t) r = m;
                else l = m;
            }
            if (r == n) {
                break;
            }
            int v[2];
            forn(i, 0, 2) v[i] = a[i][r] - (cur ? a[i][cur - 1] : 0);
            if (v[0] < t && v[1] < t) {
                ok = false;
                break;
            }
            forn(i, 0, 2) if (v[i] >= t) ++rs[i];
            cur = r + 1;
        }
        int s = -1;
        if (rs[0] > rs[1]) {
            if (n == 1 && a[0][n - 1]) s = rs[0];
            if (n > 1 && a[0][n - 1] > a[0][n - 2]) s = rs[0];
        }
        if (rs[0] < rs[1]) {
            if (n == 1 && a[1][n - 1]) s = rs[1];
            if (n > 1 && a[1][n - 1] > a[1][n - 2]) s = rs[1];
        }
        if (s == -1) ok = false;
        if (cur != n) ok = false;
        /*if (s == 3 && t == 1) {
            cerr << cur << '\n';
            cerr << rs[0] << ' ' << rs[1] << '\n';
        }*/
        if (ok) {
            ans.eb(s, t);
        }
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (auto p : ans) cout << p.fs << ' ' << p.sn << '\n';
}