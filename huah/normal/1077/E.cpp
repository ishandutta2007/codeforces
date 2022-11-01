#include<bits/stdc++.h>
using namespace std;
map<int,int>vis;
int a[200005];
int n,k,cnt=0;
int Binary(int l,int r,int x)
{
    int ans=-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(a[m]>=x) r=m-1,ans=m;
        else l=m+1;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int s;
        scanf("%d",&s);
        if(!vis[s])
        {
            vis[s]=++cnt;
            a[cnt]=1;
        }
        else a[vis[s]]++;
    }
    sort(a+1,a+1+cnt);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int num=0,p=i,f=0,ma=0;
        while(1)
        {
            f=Binary(f+1,cnt,p);
            if(f==-1) break;
            ma+=p;
            num+=p;
            p*=2;
        }
        ans=max(ans,num);
    }
    cout<<ans<<endl;
}