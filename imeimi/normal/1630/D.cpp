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

int gcd(int x, int y) {
    for (; y; swap(x, y)) x %= y;
    return x;
}

int A[1000005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        }
        int g = 0;
        for (int i = 1; i <= m; ++i) {
            int b;
            cin >> b;
            g = gcd(g, b);
        }
        vector<int> cnt(g, 0);
        vector<int> mn(g, 1e9 + 5);
        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += abs(A[i]);
            if (A[i] < 0) ++cnt[i % g];
            mn[i % g] = min(mn[i % g], abs(A[i]));
        }
        ll oe[2] = {};
        for (int i = 0; i < g; ++i) {
            oe[cnt[i] & 1] += mn[i];
        }
        printf("%lld\n", sum - min(oe[0], oe[1]) * 2);
    }
    return 0;
}