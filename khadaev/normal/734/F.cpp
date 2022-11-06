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
    cout << "-1\n";
    exit(0);
}

ll parts[30];

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> b(n), c(n);
    forn(i, 0, n) cin >> b[i];
    forn(i, 0, n) cin >> c[i];
    ll Sum = 0;
    forn(i, 0, n) Sum += b[i];
    forn(i, 0, n) Sum += c[i];
    if (Sum % (2 * n)) fail();
    Sum /= (2 * n);
    vector<ll> a(n);
    forn(i, 0, n) {
        a[i] = b[i] + c[i] - Sum;
        if (a[i] < 0) fail();
        if (a[i] % n) fail();
        a[i] /= n;
    }
    forn(i, 0, n) {
        forn(j, 0, 30) {
            if (a[i] & (1 << j)) {
                parts[j] += (1 << j);
            }
        }
    }
    forn(i, 0, n) {
        ll test = 0;
        forn(j, 0, 30) {
            if (a[i] & (1 << j)) {
                test += parts[j];
            }
        }
        if (test != b[i]) fail();
    }
    forn(i, 0, n) cout << a[i] << ' ';
}