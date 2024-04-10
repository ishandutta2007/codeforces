#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int n, A[MAXN];

bool check()
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += A[i];
        if (s == 0)
            return 0;
    }
    puts("YES");
    for (int i = 0; i < n; i++)
        printf("%d%c", A[i], i < n - 1 ? ' ' : '\n');
    return 1;
}

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        sort(A, A + n);
        if (check())
            continue;
        reverse(A, A + n);
        if (!check())
            puts("NO");
    }
    return 0;
}