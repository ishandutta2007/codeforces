#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,int>vis;
int n,cnt=0;
ll a[200005],ans[200005];
int main()
{
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),vis[a[i]]++,sum+=a[i];
    for(int i=1;i<=n;i++)
    {
        ll t=sum-a[i];
        if(t%2) continue;
        t/=2;
        if(a[i]==t&&vis[a[i]]>1) ans[cnt++]=i;
        else if(a[i]!=t&&vis[t]) ans[cnt++]=i;
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
        printf(i==0?"%d":" %d",ans[i]);
}