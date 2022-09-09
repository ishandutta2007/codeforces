#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long a[205][205], sum[205][205], dp[205][205], Minn[205][205], ans[205];

long long Query(int x1, int x2, int y1, int y2)
{
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
long long Out(int x, int y)
{
    if (y < x)
        return 0;
    return Query(1, x - 1, x, y) + Query(y + 1, n, x, y);
}
void Find(int L, int R, int x)
{
    if (L > R)
        return;
    ans[Minn[L][R]] = x;
    Find(L, Minn[L][R] - 1, Minn[L][R]);
    Find(Minn[L][R] + 1, R, Minn[L][R]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &a[i][j]);
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] += sum[i - 1][j];
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            dp[i][j] = 1e18;
            for (int k = i; k <= j; k++)
            {
                if (Out(i, k - 1) + Out(k + 1, j) + dp[i][k - 1] + dp[k + 1][j] < dp[i][j])
                {
                    dp[i][j] = min(dp[i][j], Out(i, k - 1) + Out(k + 1, j) + dp[i][k - 1] + dp[k + 1][j]);
                    Minn[i][j] = k;
                }
            }
            // printf("dp[%d][%d]= %lld Minn = %d\n", i, j, dp[i][j], Minn[i][j]);
        }
    }
    Find(1, n, 0);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");
}