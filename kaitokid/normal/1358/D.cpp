#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009],f[200009],s[200009];
ll n,x;
ll go(ll r,ll l,ll p)
{
    ll g=a[l];
    ll q=a[l]-(s[l]-p);
    ll res=g*(g+1)/2-(q)*(q-1)/2;
    //cout<<g<<" "<<q<<" "<<res<<endl;
    if(l==r)return res;
    l++;
    l%=n;

    if(r>=l){res+=f[r]-f[l-1];return res;}
    res+=f[r]+f[n-1]-f[l-1];
    return res;
}
int main()
{
    ios::sync_with_stdio(0);

    cin>>n>>x;
    for(int i=0;i<n;i++){cin>>a[i];f[i]=a[i]*(a[i]+1)/2+f[i-1];s[i]+=s[i-1]+a[i];}
ll hh=(x/s[n-1])*f[n-1];
x%=s[n-1];
ll ans=0;
if(x==0){cout<<hh;return 0;}
for(int i=0;i<n;i++)
{
    //cout<<i<<endl;
    ll p=s[i]-x+1;
    if(p<=0)p+=s[n-1];
    ll *it =upper_bound(s,s+n,p-1);
int l=(it-s);
ans=max(ans,go(i,l,p));
//cout<<i<<" "<<l<<" "<<ans<<" "<<p<<endl;
}
cout<<hh+ans;
    return 0;
}