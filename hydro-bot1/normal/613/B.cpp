// Hydro submission #622b545b724815af336d5f63@1647006811614
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int high, cf, cm, n, m;
int level[maxn], b[maxn], s[maxn], ans, tmp1, tmp2;
bool cmp(int x, int y)
{
    return level[x] < level[y];
}
int check(int x, int rr)
{
    int l, r, mid;
    l = 0;
    r = rr;
    while (l < r)
    {
        mid = (l + r + 1) >> 1;
        if (level[b[mid]] < x)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
signed main()
{
    scanf("%lld%lld%lld%lld%lld", &n, &high, &cf, &cm, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &level[i]);
        b[i] = i;
    }
    sort(b + 1, b + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + level[b[i]];
    m += s[n];
    ans = -1;
    int i;
    for (i = 1; i <= n + 1; i++)
    {
        if (high * (n - i + 1) + s[i - 1] > m)
            continue;
        if (i == 1)
            ans = cf * n + cm * high, tmp1 = 1;
        if (i == 1)
            break;
        int l = level[b[1]], r = high;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            int t = check(mid, i - 1);
            if (high * (n + 1 - i) + mid * t + s[i - 1] - s[t] <= m)
                l = mid;
            else
                r = mid - 1;
        }
        if (ans < cf * (n + 1 - i) + l * cm)
            ans = cf * (n + 1 - i) + l * cm, tmp1 = i, tmp2 = l;
    }
    printf("%lld\n", ans);
    for (i = 1; i < tmp1; i++)
        if (level[b[i]] < tmp2)
            level[b[i]] = tmp2;
    for (i = tmp1; i <= n; i++)
        level[b[i]] = high;
    for (i = 1; i <= n; i++)
        printf("%lld ", level[i]);
    return 0;
}
/*



O(n^2)




*/