#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

const int MAXN=300005;

int a[MAXN];
ULL w[MAXN],sum[MAXN],h[MAXN];

int solve(int n)
{
    int ret=0;
    for (int i=1;i<=n;i++)
        sum[i]=sum[i-1]^w[a[i]];
    for (int i=1;i<=n;i++)
        if (a[i]==1)
            for (int j=i+1,mx=1;j<=n&&a[j]!=1;j++)
            {
                mx=max(mx,a[j]);
                if (j>=mx&&(sum[j]^sum[j-mx])==h[mx])
                    ret++;
            }
    return ret;
}

int main()
{
    #ifdef KeyID
        freopen("read.txt","r",stdin);
    #endif
    int n;
    scanf("%d",&n);
    mt19937_64 gen(time(NULL));
    for (int i=1;i<=n;i++)
        w[i]=gen();
    for (int i=1;i<=n;i++)
        h[i]=h[i-1]^w[i];
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0;
    for (int i=1;i<=n;i++)
        if (a[i]==1)
            ans++;
    ans+=solve(n);
    reverse(a+1,a+n+1);
    ans+=solve(n);
    printf("%d",ans);
    return 0;
}