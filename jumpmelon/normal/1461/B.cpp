#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int MAXN = 500;
char S[MAXN + 1][MAXN + 2];
int L[MAXN + 1][MAXN + 2], R[MAXN + 1][MAXN + 2];

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n, m;
        big ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%s", S[i] + 1);
        for (int i = 1; i <= n; i++)
        {
            L[i][0] = 0;
            for (int j = 1; j <= m; j++)
                L[i][j] = S[i][j] == '*' ? L[i][j - 1] : j;
            R[i][m + 1] = m + 1;
            for (int j = m; j >= 1; j--)
                R[i][j] = S[i][j] == '*' ? R[i][j + 1] : j;
        }
        for (int j = 1; j <= m; j++)
            for (int i = 1, p = 1; i <= n; i++)
            {
                while (p <= n && j - L[p][j] >= p - i + 1 && R[p][j] - j >= p - i + 1)
                    p++;
                ans += p - i;
            }
        printf("%lld\n", ans);
    }
    return 0;
}