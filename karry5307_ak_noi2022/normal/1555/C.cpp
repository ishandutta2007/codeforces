#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[100005],b[100005],suma[100005],sumb[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            sumb[i]=sumb[i-1]+b[i];
        }
        suma[n+1]=0;
        for(int i=n;i>=1;i--)
        {
            suma[i]=suma[i+1]+a[i];
        }
        int ans=2e9;
        for(int i=1;i<=n;i++)
        {
            ans=min(ans,max(sumb[i-1],suma[i+1]));
        }
        if(ans==2e9) printf("0\n");
        else printf("%d\n",ans);
    }
}