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

const int N = 2e5 + 10;
int ans[N];
int p[N], x[N], y[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    forn(i, 0, n) {
        cin >> x[i] >> y[i];
        --x[i], --y[i];
        p[x[i]] = y[i];
        p[y[i]] = x[i];
    }
    forn(i, 0, 2 * n) {
        if (ans[i]) continue;
        int j = i;
        do {
            ans[j] = 1;
            j = p[j];
            ans[j] = 2;
            if (j % 2) --j;
            else ++j;
        } while (j != i);
    }
    forn(i, 0, n) cout << ans[x[i]] << ' ' << ans[y[i]] << '\n';
}