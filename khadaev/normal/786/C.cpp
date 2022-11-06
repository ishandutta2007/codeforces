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
int a[N], cnt[N];
int n;

int solve(int k) {
    int ans = 0, i = 0;
    while (i < n) {
        int dif = 0;
        int ii = i;
        while (dif <= k && i < n) {
            if (cnt[a[i]] == 0) ++dif;
            ++cnt[a[i]];
            ++i;
        }
        forn(j, ii, i) --cnt[a[j]];
        if (dif > k) --i;
        ++ans;
    }
    return ans;
}

int rez[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int SQRT = 2 * sqrt(n);
    fore(i, 0, n) rez[i] = INF;
    forn(i, 0, n) cin >> a[i];
    fore(i, 1, SQRT) rez[i] = solve(i);
    ford(i, 1, n / SQRT + 5) {
        int l = 1, r = n + 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (solve(m) > i) l = m;
            else r = m;
        }
        fore(j, r, n) {
            rez[j] = min(i, rez[j]);
        }
    }
    fore(i, 1, n) cout << rez[i] << ' ';
}