#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

const int mod = 1e9 + 7;

ll mul(ll x, ll y) {
    return (x % mod) * (y % mod) % mod;
}

ll F[500005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int m;
    cin >> m;
    F[0] = 1;
    for (int i = 1; i <= m; ++i) F[i] = F[i - 1] * i % mod;
    vector<int> C(m, 0);
    ll n = 0, idx = 1, E[2] = { 0, 0 };
    for (int &i : C) {
        cin >> i;
        n += i;
        idx += (i + 1) / 2;
        E[i - 1 & 1] += 1;
    }
    sort(C.begin(), C.end());
    int p = 1;
    ll ans = 0, count = F[E[0]];
    for (int i : C) {
        for (; p < i; ++p) {
            ll nxt = idx + E[p & 1];
            ans = (ans + p * mul(E[p & 1], (2 * idx - n - 1) + (2 * (nxt - 1) - n - 1))) % mod;
            count = count * F[E[p & 1]] % mod * F[E[p & 1]] % mod;
            idx = nxt;
        }
        E[i - 1 & 1] -= 1;
    }
    printf("%lld %lld\n", mul(ans, (mod + 1) / 2), count);
    return 0;
}