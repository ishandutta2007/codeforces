#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long fact[200005],invfact[200005],h=1e9+7;
long po(long a,long b)
{
    if(a==0) return 0;
    if(a==1 || b==0) return 1;
    long m=po(a,b/2);
    if(b%2) return (((m*m)%h)*a)%h;
    return (m*m)%h;
}
long ncr(long n,long r)
{
    if(n<r) return 0;
    return (fact[n]*((invfact[n-r]*invfact[r])%h))%h;
}
int main()
{
    io
    vll v;
    long n,k,i,x,y,c=0,t,tt,cc,ans=0;
    fact[0]=invfact[0]=1;
    cin>>n>>k;
    for(i=1;i<=n+1;++i)
    {
        fact[i]=(i*fact[i-1])%h;
        invfact[i]=(po(i,h-2)*invfact[i-1])%h;
    }
    for(i=0;i<n;++i)
    {
        cin>>x>>y;
        v.pb({x,-1});
        v.pb({y,1});
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();)
    {
        t=v[i].first;
        if(v[i].second==-1)
        {
            while(v[i].first==t && v[i].second==-1)
            c++,i++;
            ans=(ans+(ncr(c,k)*((v[i].first-t+(v[i].second==1))%h))%h)%h;
        }
        else
        {
            while(v[i].first==t && v[i].second==1)
            c--,i++;
            if(i>=v.size()) break;
            ans=(ans+(ncr(c,k)*((v[i].first-t-1+(v[i].second==1))%h))%h)%h;
        }
    }
    cout<<ans;
    return 0;
}