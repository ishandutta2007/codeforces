#include <bits/stdc++.h>+
#define pb push_back
using namespace std;
vector < long long > v;
long long n,x[200005],c[200005]={0},i,ans=1,h=1e9+7,s=0,p[200005],y,cnt,visi[20005]={0},d=2,t;
int main()
{
    p[0]=1;
    cin>>n;
    for(i=1;i<=n+2;++i)
    p[i]=(d*p[i-1])%h;
    for(i=1;i<=n;++i)
    cin>>x[i];
    for(i=1;i<=n;++i)
    if(c[i]==0)
    {
        y=i;
        while(c[y]==0)
        {
            c[y]=cnt++;
            y=x[y];
        }
        if(c[y]>=t)
        v.pb(cnt-c[y]);
        t=cnt;
    }
    for(i=0;i<v.size();++i)
    {
        s+=v[i];
        ans=(ans*(p[v[i]]-2+h)%h)%h;
    }
    ans=(ans*p[n-s])%h;
    cout<<ans;
    return 0;
}