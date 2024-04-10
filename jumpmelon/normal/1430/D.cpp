#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int A[MAXN + 1];
char S[MAXN + 1];

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n, m = 0, c = 0;
        char pre = 0;
        scanf("%d", &n);
        scanf("%s", S);
        for (int i = 0; i <= n; i++)
        {
            if (S[i] != pre)
            {
                if (c)
                    A[m++] = c;
                c = 0;
                pre = S[i];
            }
            c++;
        }
        int ans = 0;
        for (int i = 0, p = 0; i < m; i++)
        {
            while (p < m && (p < i || A[p] == 1))
                p++;
            if (p < m)
                A[p]--;
            else
                m--;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}