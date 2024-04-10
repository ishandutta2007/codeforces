#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long q(long n)
{
    long i,ans=n,c;
    vll v;
    for(i=2;i*i<=n;++i)
    if(n%i==0)
    {
        c=0;
        while(n%i==0)
        n/=i,c++;
        v.pb({i,c});
    }
    if(n!=1) v.pb({n,1});
    n=v.size();
    for(i=0;i<n;++i)
    ans=(ans/v[i].first)*(v[i].first-1);
    return ans;
}
int main()
{
    io
    long n,k,i,h=1e9+7;
    cin>>n>>k;
    for(i=0;i<(k+1)/2;++i)
    {
        n=q(n);
        if(n==1) break;
    }
    cout<<n%h;
    return 0;
}