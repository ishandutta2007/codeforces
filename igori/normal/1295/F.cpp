#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int n;
long long l[500], r[500];
long long q = 1;
long long x[1000];

long long inq(long long a, long long x)
{
    if (x == 0) return 1;
    long long l = inq(a, x / 2);
    if (x % 2) return l * l % MOD * a % MOD;
    return l * l % MOD;
}


long long cnk(long long n, long long k)
{
    if (k == 0) return 1LL;
    return cnk(n, k - 1) * inq(k, MOD - 2) % MOD * (n - k + 1) % MOD;
}

long long kek(long long len, long long elems)
{
    return cnk(len + elems - 1, elems);
}

long long dp[500][1000];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[n - i - 1] >> r[n - i - 1];
        r[n - i - 1]++;
    }
    for (int i = 0; i < n; i++)
    {
        x[2 * i] = l[i];
        x[2 * i + 1] = r[i];
    }
    sort(x, x + 2 * n);
    for (int segm = 0; segm + 1 < 2 * n; segm++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = i; k >= 0; k--)
            {
                if (l[k] <= x[segm] && x[segm + 1] <= r[k])
                {
                    long long val = kek(x[segm + 1] - x[segm], i - k + 1);
                    long long kep = 0;
                    if (k != 0)
                        for (int e = segm - 1; e >= 0; e--)
                        {
                            kep = (kep + dp[k - 1][e]) % MOD;
                        }
                    else
                        kep = 1;
                    dp[i][segm] = (dp[i][segm] + kep * val) % MOD;
                }
                else break;
            }
        }
    }
    long long ans = 0;
    for (int s = 0; s < 2 * n; s++)
    {
        ans = (ans + dp[n - 1][s]) % MOD;
    }
    for (int i = 0; i < n; i++) q = q * (r[i] - l[i]) % MOD;
    cout << ans * inq(q, MOD - 2) % MOD;
}