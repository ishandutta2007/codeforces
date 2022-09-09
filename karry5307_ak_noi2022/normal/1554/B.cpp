#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,k,a[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        long long ans=-1e9;
        for(int i=max(1,n-105);i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,((long long)i)*j-(a[i]|a[j])*k);
            }
        }
        printf("%lld\n",ans);
    }
}