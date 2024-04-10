#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int X[MAXN + 1], Y[MAXN + 1];

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &X[i], &Y[i]);
        int ans = -1;
        for (int i = 1; i <= n; i++)
        {
            bool fl = 1;
            for (int j = 1; j <= n; j++)
                if (abs(X[i] - X[j]) + abs(Y[i] - Y[j]) > k)
                {
                    fl = 0;
                    break;
                }
            if (fl)
            {
                ans = 1;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}