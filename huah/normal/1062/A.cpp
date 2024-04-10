#include<bits/stdc++.h>
using namespace std;
bool vis[1005];
int a[1005];
int main()
{
    memset(vis,false,sizeof(vis));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=2;i<=n;i++) vis[a[i]-a[i-1]-1]=true;
    int l=1,ans=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1]+1)
        {
            if(a[l]==1) ans=max(ans,i-1-l);
            else ans=max(ans,i-1-l-1);
            l=i;
        }
    }
    if(a[n]==a[n-1]+1)
        if(a[n]==1000||a[l]==1) ans=max(ans,n-l);
    else ans=max(ans,n-l-1);
    printf("%d\n",ans);
}