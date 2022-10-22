#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000, INF = 0x3f3f3f3f;
int F[MAXN + 1];
struct point { int t, x, y; } A[MAXN + 1];

int main()
{
    int r, n;
    scanf("%d%d", &r, &n);
    A[0] = {0, 1, 1};
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &A[i].t, &A[i].x, &A[i].y);
    int m = (r - 1) * 2, mx = -INF, ans = 0;
    for (int i = 1, p = 0; i <= n; i++)
    {
        while (p < i && A[i].t - A[p].t >= m)
            mx = max(mx, F[p++]);
        F[i] = mx + 1;
        for (int j = p; j < i; j++)
            if (abs(A[i].x - A[j].x) + abs(A[i].y - A[j].y) <= A[i].t - A[j].t)
                F[i] = max(F[i], F[j] + 1);
        ans = max(ans, F[i]);
    }
    printf("%d\n", ans);
    return 0;
}