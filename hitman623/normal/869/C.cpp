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
long a,b,c,h=998244353;
long fact[100005],i,invfac[10004];
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
    if(n<r || r<0) return 0;
    return (((fact[n]*invfac[r])%h)*invfac[n-r])%h;
}
int main()
{
    io
    long i;
    fact[0]=1;
    invfac[0]=1;
    for(i=1;i<=10005;++i)
    {
        fact[i]=(i*fact[i-1])%h;
        invfac[i]=po(fact[i],h-2);
    }
    cin>>a>>b>>c;
    long ans=1,ans1=0,ans2=0,ans3=0,t1;
    for(i=0;i<=min(a,b);++i)
    {
        t1=1;
        t1=(t1*ncr(a,i))%h;
        t1=(t1*ncr(b,i))%h;
        t1=(t1*fact[i])%h;
        ans1=(ans1+t1)%h;
    }
    for(i=0;i<=min(b,c);++i)
    {
        t1=1;
        t1=(t1*ncr(b,i))%h;
        t1=(t1*ncr(c,i))%h;
        t1=(t1*fact[i])%h;
        ans2=(ans2+t1)%h;
    }
    for(i=0;i<=min(c,a);++i)
    {
        t1=1;
        t1=(t1*ncr(c,i))%h;
        t1=(t1*ncr(a,i))%h;
        t1=(t1*fact[i])%h;
        ans3=(ans3+t1)%h;
    }
    ans=(ans1*ans2)%h;
    ans=(ans*ans3)%h;
    cout<<ans;
    return 0;
}