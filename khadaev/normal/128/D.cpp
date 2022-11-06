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

void fail() {
    cout << "NO\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n % 2) fail();
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    int mn = INF;
    forn(i, 0, n) mn = min(mn, a[i]);
    vector<int> cnt(n);
    forn(i, 0, n) {
        a[i] -= mn;
        if (a[i] >= n) fail();
        ++cnt[a[i]];
    }
    int rest = n;
    forn(i, 0, n - 1) {
        if (cnt[i + 1] < cnt[i]) fail();
        if (cnt[i + 1] == cnt[i]) {
            if (2 * cnt[i] == rest) break;
            else fail();
        } else {
            cnt[i + 1] -= cnt[i];
            rest -= 2 * cnt[i];
            cnt[i] = 0;
        }
    }
    if (cnt[n - 1]) fail();
    cout << "YES\n";
    return 0;
}