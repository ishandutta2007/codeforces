#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int MAXN = 100000;
int A[MAXN + 1], C[MAXN + 1];
priority_queue<pair<big, int>> Q;

big f(int x, int k)
{
    int v1 = x / k, v2 = v1 + 1;
    int r2 = x % k, r1 = k - r2;
    return (big)v1 * v1 * r1 + (big)v2 * v2 * r2;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
        C[i] = 1;
        if (C[i] < A[i])
            Q.push({f(A[i], C[i]) - f(A[i], C[i] + 1), i});
        k--;
    }
    while (!Q.empty() && k--)
    {
        int i = Q.top().second;
        Q.pop();
        C[i]++;
        if (C[i] < A[i])
            Q.push({f(A[i], C[i]) - f(A[i], C[i] + 1), i});
    }
    big ans = 0;
    for (int i = 1; i <= n; i++)
        ans += f(A[i], C[i]);
    printf("%lld\n", ans);
    return 0;
}