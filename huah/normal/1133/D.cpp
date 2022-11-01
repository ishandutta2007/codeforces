#include<bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005];
map<pair<int,int>,int>mp;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    {
        int t;
        if(a[i]==0||b[i]==0)
            t=1;
        else
            t=__gcd(abs(a[i]),abs(b[i]));
        a[i]/=t,b[i]/=t;
        if(a[i]<0)
            a[i]*=-1,b[i]*=-1;
    }
    int ans=0,z=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0&&b[i]!=0) continue;
        if(a[i]!=0&&b[i]==0) ans=max(ans,++mp[make_pair(1e9+1,0)]);
        else if(a[i]==0&&b[i]==0)
            z++;
        else
            ans=max(ans,++mp[make_pair(a[i],b[i])]);
    }
    cout<<ans+z<<endl;
}