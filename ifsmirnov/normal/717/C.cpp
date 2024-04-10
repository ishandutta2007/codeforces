#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
int a[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n)
        cin >> a[i];
    sort(a, a + n);
    const int mod = 10007;
    ll x = 0;
    forn (i, n) {
        ll cur = (a[i] * ll(a[n - i - 1])) % mod;
        x += cur;
    }
    x %= mod;
    cout << x << '\n';
}