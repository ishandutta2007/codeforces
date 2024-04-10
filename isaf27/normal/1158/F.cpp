#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 3010;
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;
const int MG = 10;
const int MS = (1 << MG);

inline int power(int a, int k)
{
    if (k == 0) return 1;
    int t = power(a, k >> 1);
    t = 1LL * t * t % MOD;
    if (k & 1) t = 1LL * a * t % MOD;
    return t;
}

int n, c, a[M], kol[M][M], pw[M], inv[M], k, cnt, now, dp[M][M], ans[M], cost[M][M], pr, f[M][MS], to;
ll sum;
bool used[M];

inline void solve_n2k()
{
    for (int i = 0; i <= n; i++) inv[i] = power(pw[i] - 1, MOD - 2);
    for (int i = 0; i < n; i++)
    {
        cnt = c;
        pr = 1;
        for (int j = i; j < n; j++)
        {
            if (kol[a[j]][i] == kol[a[j]][j])
                cnt--;
            else
                pr = 1LL * pr * inv[kol[a[j]][j] - kol[a[j]][i]] % MOD;
            if (cnt != 0)
                cost[i][j] = 0;
            else
                cost[i][j] = pr;
            pr = 1LL * pr * (pw[kol[a[j]][j] - kol[a[j]][i] + 1] - 1) % MOD;
        }
    }
    for (int i = 0; i <= n; i++) dp[0][i] = 0;
    dp[0][0] = 1;
    for (int r = 1; r <= k; r++)
    {
        dp[r][0] = 0;
        for (int i = r * c - 1; i < n; i++)
        {
            sum = 0;
            for (int j = i; j >= (r - 1) * c; j--)
            {
                sum += 1LL * cost[j][i] * dp[r - 1][j];
                if (sum >= MOD2) sum -= MOD2;
            }
            dp[r][i + 1] = (sum % (ll)MOD);
        }
    }
}

inline void solve_nk2powc()
{
    dp[0][0] = 1;
    f[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int x = 1; x <= k; x++) dp[x][i + 1] = f[x - 1][((1 << c) - 1) ^ (1 << a[i])];
        to = min(k - 1, (i / c));
        for (int ms = (1 << c) - 1; ms >= 0; ms--)
            if ((ms >> a[i]) & 1)
                for (int x = 0; x <= to; x++)
                {
                    f[x][ms] += f[x][ms];
                    if (f[x][ms] >= MOD) f[x][ms] -= MOD;
                    f[x][ms] += f[x][ms ^ (1 << a[i])];
                    if (f[x][ms] >= MOD) f[x][ms] -= MOD;
                }
        for (int x = 0; x < k; x++)
        {
            f[x][0] += dp[x][i + 1];
            if (f[x][0] >= MOD) f[x][0] -= MOD;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < c; i++)
    {
        kol[i][0] = 0;
        for (int x = 0; x < n; x++)
        {
            kol[i][x + 1] = kol[i][x];
            if (a[x] == i) kol[i][x + 1]++;
        }
    }
    pw[0] = 1;
    for (int i = 0; i < n; i++)
    {
        pw[i + 1] = pw[i] + pw[i];
        if (pw[i + 1] >= MOD) pw[i + 1] -= MOD;
    }
    for (int i = 0; i < c; i++) used[i] = false;
    k = 0;
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!used[a[i]])
        {
            used[a[i]] = true;
            cnt++;
        }
        if (cnt == c)
        {
            cnt = 0;
            for (int i = 0; i < c; i++) used[i] = false;
            k++;
        }
    }
    if (c <= MG)
        solve_nk2powc();
    else
        solve_n2k();
    for (int i = 0; i <= n; i++) ans[i] = 0;
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= n; j++)
        {
            ans[i] += 1LL * dp[i][j] * pw[n - j] % MOD;
            if (ans[i] >= MOD) ans[i] -= MOD;
        }
    for (int i = 0; i < n; i++)
    {
        ans[i] -= ans[i + 1];
        if (ans[i] < 0) ans[i] += MOD;
    }
    ans[0]--;
    if (ans[0] < 0) ans[0] += MOD;
    for (int i = 0; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}