#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long n,i,f=1,h=1e9+7,ans=0,term=1;
vl v(200005),vv;
long po(long a,long b)
{
    if(a==0) return 0;
    if(b==0 || a==1) return 1;
    long m=po(a,b/2);
    if(b&1) return (((m*m)%h)*a)%h;
    return (m*m)%h;
}
int main()
{
    io
    cin>>n;
    for(i=0;i<n;++i)
    cin>>v[i];
    while(n%4!=1)
    {
        for(i=0;i<n-1;++i,f=!f)
        if(f) v[i]=(v[i]+v[i+1])%h;
        else v[i]=(v[i]-v[i+1]+h)%h;
        n--;
    }
    for(i=0;i<(n+1)/2;++i)
    {
        ans=(ans+term*(v[2*i]))%h;
        term=(term*(n/2-i))%h;
        term=(term*po(i+1,h-2))%h;
    }
    cout<<ans;
    return 0;
}