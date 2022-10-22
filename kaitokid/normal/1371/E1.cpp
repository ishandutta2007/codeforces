#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//vector<int>ans;
//map<ll,ll>d;
ll n,p,mn,mx;
ll d[200009],f[200009];
bool ans[200009];
ll res;
void go(ll x,ll s)
{
    if(x<0)return;
    if(x<s)return;
    if(ans[x])return;
  if(x<=mx-mn)  res--;
    ans[x]=true;
    go(x-p,s);
}
int main()
{ios::sync_with_stdio(0);
cin>>n>>p;
 mn=1e9,mx=0;
for(int i=0;i<n;i++)
{
    cin>>d[i];
mx=max(d[i],mx);
mn=min(mn,d[i]);
}
mn=max(mn,mx-(n-1));
for(int i=0;i<n;i++)
{
  ll x=d[i]-mn;
  if(x<0)x=0;
  f[x]++;
}
// fr=0,en=mx-mn;
res=mx-mn+1;
for(ll i=0;i<=(mx-mn)+n;i++)
{
    f[i]+=f[i-1];
    //if(f[i]<p)continue;

    ll u=i-f[i]%p;
ll s=i-(n-1);
//cout<<mn+i<<" "<<u<<endl;
    go(u,s);
}
//if(en<fr){cout<<0;return 0;}
cout<<res<<endl;
for(ll i=0;i<=mx-mn;i++)
{
    if(ans[i])continue;
    cout<<(mn+i)<<" ";
}
return 0;
}