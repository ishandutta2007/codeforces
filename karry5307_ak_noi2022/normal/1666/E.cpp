#include <cstdio>
#include <algorithm>
using namespace std;
int n, l, Minn, Maxn, a[100005], MinR[100005], MaxR[100005], ansL[100005], ansR[100005];

long long f[100005];
bool check1(long long x)
{
    // printf("- %lld\n", x);
    long long Maxn = -1e15;
    for (int i = 1; i <= n; i++)
    {
        f[i] = a[i] - i * x;
        if (f[i] - Maxn < -x)
            return false;
        Maxn = max(Maxn, f[i]);
    }
    return true;
}

bool check2(long long x)
{
    // printf("-- %lld\n", x);
    long long Minn = 1e15;
    for (int i = 1; i <= n; i++)
    {
        f[i] = a[i] - i * x;
        if (f[i] - Minn > x)
            return false;
        Minn = min(Minn, f[i]);
    }
    return true;
}

int main()
{
    scanf("%d%d", &l, &n);
    Minn = l / n, Maxn = (l - 1) / n + 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (i != 1)
            Minn = min(Minn, a[i] / (i - 1));
        if (i != n)
            Minn = min(Minn, (l - a[i]) / (n - i));
        Maxn = max(Maxn, (l - a[i] - 1) / (n - i + 1) + 1);
        Maxn = max(Maxn, ((a[i] - 1) / i) + 1);
    }
    int L = 0, R = Minn;
    while (L < R)
    {
        int Mid = (L + R + 1) / 2;
        if (check1(Mid))
            L = Mid;
        else
            R = Mid - 1;
    }
    Minn = min(Minn, L);

    L = Maxn, R = l;
    while (L < R)
    {
        int Mid = (L + R) / 2;
        if (check2(Mid))
            R = Mid;
        else
            L = Mid + 1;
    }
    Maxn = max(Maxn, L);

    a[n + 1] = l;
    for (int i = 1; i <= n; i++)
    {
        MinR[i] = max(MinR[i - 1] + Minn, a[i]);
        MaxR[i] = min(MaxR[i - 1] + Maxn, a[i + 1]);
    }
    int Now = l;
    for (int i = n; i >= 1; i--)
    {
        ansR[i] = Now;
        ansL[i] = max(MinR[i - 1], Now - Maxn);
        Now = ansL[i];
    }
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", ansL[i], ansR[i]);
}