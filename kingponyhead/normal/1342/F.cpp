// KingPonyHead
#include<bits/stdc++.h>
using namespace std;
const int N = 15, Mod = 1e9 + 7;
int n, m, q, A[N], SM[1 << N], F[N], R[N], par[1 << N][N];
pair < int , int > dp[1 << N][N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> q;
    for (; q; q --)
    {
        cin >> n;
        for (int i = 0; i < n; i ++)
            cin >> A[i];
        for (int mask = 1; mask < (1 << n); mask ++)
        {
            SM[mask] = SM[mask - (mask & - mask)];
            SM[mask] += A[__builtin_ctz(mask)];
        }
        for (int mask = 1; mask < (1 << n); mask ++)
        {
            for (int i = 0; i < n; i ++)
                dp[mask][i] = {-N, -Mod}, par[mask][i] = -Mod;
            dp[mask][__builtin_ctz(mask)] = {1, -SM[mask]};
            for (int sub = mask & (mask - 1); sub; sub = (sub - 1) & mask)
                for (int i = 1; i < n; i ++)
                    if ((sub >> i & 1) && - dp[mask ^ sub][i - 1].second < SM[sub])
                    {
                        if (dp[mask][i] < make_pair(dp[mask ^ sub][i - 1].first + 1, - SM[sub]))
                            dp[mask][i] = make_pair(dp[mask ^ sub][i - 1].first + 1, - SM[sub]), par[mask][i] = sub;
                    }
            for (int i = 1; i < n; i ++)
            {
                if (dp[mask][i] < dp[mask][i - 1])
                    dp[mask][i] = dp[mask][i - 1], par[mask][i] = -1;
            }
        }
        int msk = 15, mi = 3;
        int now = (1 << n) - 1, ptr = n - 1;
        printf("%d\n", n - dp[now][ptr].first);
        while (now)
        {
            while (par[now][ptr] == -1)
                ptr --;
            if (dp[now][ptr].first == 1)
            {
                for (int i = 0; i < n; i ++)
                    if (now >> i & 1)
                        R[i] = ptr;
                break;
            }
            int sub = par[now][ptr];
            for (int j = 0; j < n; j ++)
                if (sub >> j & 1)
                    R[j] = ptr;
            now ^= sub;
            ptr --;
        }
        for (int i = 0; i < n; i ++)
            F[i] = i;
        for (int i = 0; i < n; i ++)
            if (R[i] != i)
            {
                printf("%d %d\n", F[i] + 1, F[R[i]] + 1);
                for (int j = i + 1; j < n; j ++)
                    F[j] --;
            }
    }
    return 0;
}