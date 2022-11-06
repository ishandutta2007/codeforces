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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n);
    forn(i, 0, n) cin >> x[i];
    sort(all(x));
    n = unique(all(x)) - x.begin();
    int a, b;
    cin >> a >> b;
    int ans = 0;
    while (a > b) {
        while (n && a - a % x[n - 1] < b) --n;
        int best = a - 1;
        forn(i, 0, n) {
            int res = a - a % x[i];
            if (res >= b && res < best)
                best = res;
        }
        a = best;
        ++ans;
    }
    cout << ans << '\n';
}