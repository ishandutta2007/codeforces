#include<bits/stdc++.h>

using namespace std;
#define fi first
#define se second

const int N = 1000005;
const int INF = 1e9;
const int MOD = 998244353;

int n, m;
long long p[N];

long long inq(long long x, long long y)
{
    if (!y) return 1;
    long long l = inq(x, y / 2);
    if (y % 2) return l * l % MOD * x % MOD;
    return l * l % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    sort(p + 1, p + n + 1);
    reverse(p + 1, p + n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        p[i] += p[i - 1];
    }
    long long kek = inq(n, MOD - 2);
    for (int k = 1; k <= n; k++)
    {
        long long si = 0;
        for (int i = k; i < n + k; i += k)
        {
            si += (p[i] - p[i - k]) * (i / k - 1);
        }
        cout << si % MOD * kek % MOD << " ";
    }
}