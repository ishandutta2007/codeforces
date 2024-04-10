#include <bits/stdc++.h>

typedef long long big;

using namespace std;

const int MAXN = 200000;
int A[MAXN];

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        sort(A, A + n);
        big ans = 0;
        for (int i = 0; i <= k; i++)
            ans += A[n - i - 1];
        printf("%lld\n", ans);
    }
    return 0;
}