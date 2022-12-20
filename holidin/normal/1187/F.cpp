#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2e5 + 1;

long long l[N], r[N], vt[N];


long long bp(long long x, int st) {
    if (st == 0)
        return 1;
    else if (st % 2 == 0)
            return bp((x * x) % mod, st / 2);
        else
            return (bp((x * x) % mod, st / 2) * x) % mod;
}

int main() {
    long long i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> l[i];
    for (i = 1; i <= n; ++i)
        cin >> r[i];
    long long ans = (n * n) % mod, sum = 0;
    for (i = 1; i < n; ++i) {
        long long l1 = max(l[i], l[i + 1]);
        long long r1 = min(r[i], r[i + 1]);
        if (l1 <= r1) {
            vt[i] = ((((r1 - l1 + 1) * bp(r[i] - l[i] + 1, mod - 2)) % mod) * bp(r[i + 1] - l[i + 1] + 1, mod - 2)) % mod;
        } else
            vt[i] = 0;
        sum += vt[i];
        ans = (ans + vt[i] - 2 * vt[i] * n) % mod;
    }
    for (i = 1; i < n; ++i) {
        long long sum1 = sum - vt[i];
        if (i > 1) {
            sum1 -= vt[i - 1];
            long long l1 = max(l[i], max(l[i + 1], l[i - 1])), r1 = min(r[i], min(r[i + 1], r[i - 1]));
            if (l1 <= r1)
                ans = (ans + ((((r1 - l1 + 1) * bp(r[i] - l[i] + 1, mod - 2)) % mod) * bp(r[i + 1] - l[i + 1] + 1, mod - 2) % mod) * bp(r[i - 1] - l[i - 1] + 1, mod - 2)) % mod;
        }
        if (i < n - 1) {
            sum1 -= vt[i + 1];
            long long l1 = max(l[i], max(l[i + 1], l[i + 2])), r1 = min(r[i], min(r[i + 1], r[i + 2]));
            if (l1 <= r1)
                ans = (ans + ((((r1 - l1 + 1) * bp(r[i] - l[i] + 1, mod - 2)) % mod) * bp(r[i + 1] - l[i + 1] + 1, mod - 2) % mod) * bp(r[i + 2] - l[i + 2] + 1, mod - 2)) % mod;
        }
        sum1 %= mod;
        ans = (ans + vt[i] * sum1) % mod;
    }
    cout << (ans + mod) % mod;
}