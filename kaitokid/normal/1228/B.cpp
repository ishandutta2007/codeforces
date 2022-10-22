#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7,ans=1;
ll c[1009],r[1009];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
ll w,h;
cin>>h>>w;
for(int i=0;i<h;i++)cin>>r[i];
for(ll i=0;i<w;i++)cin>>c[i];
for(int i=0;i<h;i++)
    for(ll j=0;j<w;j++)
{
    if(i==c[j]&&j<r[i]){cout<<0;return 0;}
    if(j==r[i]&&i<c[j]){cout<<0;return 0;}
     if((i>c[j])&&j>r[i])ans=(ans*2)%mod;
}
cout<<ans;
    return 0;
}