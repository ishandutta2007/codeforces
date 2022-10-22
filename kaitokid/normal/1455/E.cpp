#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll x[6],y[6];
ll ch(int a,int b,int c,int d)
{
    ll ans=abs(x[b]-x[a])+abs(x[d]-x[c])+abs(y[a]-y[c])+abs(y[b]-y[d]);
    ll u1=x[b],u2=x[a],v1=x[d],v2=x[c];
    if(u1>u2)swap(u1,u2);
    if(v1>v2)swap(v1,v2);
    ll mx1=max(u2,v2)-min(u1,v1);
    ll mn1=max(max(u1,v1)-min(u2,v2),0LL);
     u1=y[a],u2=y[c],v1=y[b],v2=y[d];
    if(u1>u2)swap(u1,u2);
    if(v1>v2)swap(v1,v2);

    ll mx2=max(u2,v2)-min(u1,v1);
    ll mn2=max(max(u1,v1)-min(u2,v2),0LL);
    ll rr=max(0LL,max(mn1,mn2)-min(mx1,mx2));
    return ans+2*rr;
}
int main()
{
    ios::sync_with_stdio(0);
    int t;

    cin>>t;
    while(t--)
    {

    for(int i=0;i<4;i++)cin>>x[i]>>y[i];
    ll ans=100000000000000000;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
    {
        if(j==i)continue;
        for(int q=0;q<4;q++)
        {
            if(q==i||q==j)continue;
           for(int w=0;w<4;w++)
           {
               if(w==i||w==j||w==q)continue;
               ans=min(ans,ch(i,j,q,w));
           }
        }

    }
    cout<<ans<<endl;
    }
    return 0;
}