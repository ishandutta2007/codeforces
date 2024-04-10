#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;
const long long mod = 1e9 + 7;

long long mn[N], c[N], d[N], an[N];

long long bp(long long x, int st) {
    if (st == 0)
        return 1;
    else if (st % 2 == 0)
            return bp((x * x) % mod, st / 2);
        else
            return (bp((x * x) % mod, st / 2) * x) % mod;
}

int main() {
    int i, j;
    long long n, k;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 2; i <= n - 1; ++i)
        mn[i] = (long long) (i * bp(n, n - i - 1)) % mod;
    mn[n] = 1;
    c[1] = 1;
    d[1] = 1;
    for (i = 2; i <= min(n - 1, k); ++i) {
        d[i] = (d[i - 1] * (n - i)) % mod;
        c[i] = (((c[i - 1] *(k - i + 1)) % mod) * bp(i - 1, mod - 2)) % mod;
        an[i] = (c[i] * d[i]) % mod;
    }
    an[1] = 1;
    int cnt = 0;
    for (int a1 = 1; a1 <= k; ++a1)
    for (int a2 = 1; a2 <= k; ++a2)
    for (int a3 = 1; a3 <= k; ++a3)
    if (a1 + a2 + a3 < k)
        ++cnt;
    long long ans = 0;
    for (i = 1; i <= min(n - 1, k); ++i) {
        ans = (ans + ((an[i] * bp(k, n - i - 1) % mod) * mn[i + 1]) % mod) % mod;
    }
    cout << ans;
}