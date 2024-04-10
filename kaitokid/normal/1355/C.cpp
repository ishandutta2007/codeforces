#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll f[1000009],g[1000009];
int main()
{
    ios::sync_with_stdio(0);
    ll a,b,c,d;
cin>>a>>b>>c>>d;
for(ll i=a;i<=b;i++)
{
    f[i+b-2]--;
    f[i+c-1]++;

}
ll u=0,ans=0,r=0;
for(ll i=b+c;i>=c;i--)
{
    u+=f[i];
    r+=u;
   //cout<<i<<" "<<r<<" "<<f[i]<<endl;
   if(i<=d)ans+=r;
}
cout<<ans<<endl;
    return 0;
}