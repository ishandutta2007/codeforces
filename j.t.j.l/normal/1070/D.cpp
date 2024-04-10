#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N,K;
LL a[200010];

int main()
{
    scanf("%d%d",&N,&K);
    LL ans = 0;
    for (int i=1;i<=N;i++)scanf("%lld",&a[i]);
    LL x = 0;
    for (int i=1;i<=N;i++)
    {
        LL t = (x + a[i]) / K;
        if (t * K < x)
        {
            ans += t + 1;
            x = 0;
        }
        else
        {
            ans += t;
            x = (x + a[i]) % K;
        }
    }
    ans += (x + K - 1) / K;
    printf("%lld\n",ans);
}