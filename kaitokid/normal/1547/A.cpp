#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{
    ll x[3],y[3];
    for(int i=0;i<3;i++)cin>>x[i]>>y[i];
    ll ans=abs(x[0]-x[1])+abs(y[0]-y[1]);
    if(x[2]==x[0]&& x[2]==x[1])
    {
        if(y[2]>min(y[0],y[1])&& y[2]<max(y[0],y[1]))ans+=2;
    }
    if(y[2]==y[0]&& y[2]==y[1])
    {
        if(x[2]>min(x[0],x[1])&& x[2]<max(x[0],x[1]))ans+=2;
    }
    cout<<ans<<endl;
}
    return 0;
}