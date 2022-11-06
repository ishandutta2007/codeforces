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
int n;
int P[200005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    P[0] = 1;
    for (int i = 1; i <= n; ++i) P[i] = P[i - 1] * 2 % mod;
    int C[30] = {}, ans = P[n] - 1;
    for (int i = 1; i <= n; ++i) {
        int x, c;
        cin >> x;
        for (c = 0; x % 2 == 0; ++c) x /= 2;
        ++C[c];
    }
    ll mul = 1;
    for (int i = 30; --i; ) {
        if (C[i] == 0) continue;
        ans = (ans + mod - mul * P[C[i] - 1] % mod) % mod;
        mul = mul * P[C[i]] % mod;
    }
    printf("%d\n", ans);
    return 0;
}