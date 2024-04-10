#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300000;
int Ans[MAXN + 1];
int A[MAXN + 1], C[MAXN + 1];

void solve(int a, int b, int v, int len)
{
    if (len > 1 && C[v] == 1)
    {
        if (A[a] == v && C[v + 1])
        {
            Ans[len] = 1;
            solve(a + 1, b, v + 1, len - 1);
        }
        else if (A[b] == v && C[v + 1])
        {
            Ans[len] = 1;
            solve(a, b - 1, v + 1, len - 1);
        }
    }
}

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n;
        scanf("%d", &n);
        Ans[1] = 1;
        for (int i = 1; i <= n; i++)
            C[i] = 0;
        for (int i = 2; i <= n; i++)
            Ans[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &A[i]);
            C[A[i]]++;
        }
        for (int i = 1; i <= n; i++)
            if (C[i] > 1)
                Ans[1] = 0;
        solve(1, n, 1, n - 1);
        Ans[n] = C[1] ? 1 : 0;
        for (int i = 1; i <= n; i++)
            putchar(Ans[i] + '0');
        putchar('\n');
    }
    return 0;
}