// KingPonyHead
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q, A[N];
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d%d", &n, &m);
        if (m <= n)
        {
            printf("YES\n");
            continue;
        }
        if (n == 1)
        {
            printf("NO\n");
            continue;
        }
        for (int i = 0; i < 100; i ++)
        {
            if (n & 1) n --;
            n = min(3LL * n / 2, (long long)1e9);
        }
        if (m <= n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}