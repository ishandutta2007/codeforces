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

const int N = 1e6 + 10;

char used[N];
int prv[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) used[a[i]] = 1;
    int p = 0;
    forn(i, 0, 2 * N) {
        prv[i] = p;
        if (i < N && used[i]) p = i;
    }
    int ans = 0;
    forn(i, 0, N) if (used[i]) {
        for (int j = 2 * i; j < 2 * N; j += i) {
            int pr = prv[j];
            if (pr >= i) ans = max(ans, pr % i);
        }
    }
    cout << ans << '\n';
}