#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define Max(a, b) (a >= b ? a : b)
#define Min(a, b) (a <= b ? a : b)

int t, n;
int arr[55], cnt[105];

int solve()
{
    memset(cnt, 0, sizeof(cnt));
    for (register int k = n - 1; k >= 0; --k)
        ++cnt[arr[k]];

    int maxn = 2 * n, sum, ans = -1;

    for (register int s = maxn; s >= 2; --s)
    {   
        sum = 0;
        for (register int i = 1; i <= (s >> 1); ++i)
        {   
            if (i == s - i) 
                sum += cnt[i] >> 1; 
            else 
                sum += Min(cnt[i], cnt[s - i]);
        }
        ans = Max(ans, sum);
    }

    return ans;
}

int main()
{
    scanf("%d", &t);
    for (register int i = 0; i < t; ++i)
    {
        scanf("%d", &n);
        for (register int j = 0; j < n; ++j)
            scanf("%d", &arr[j]);
        printf("%d\n", solve());
    }
    return 0;
}