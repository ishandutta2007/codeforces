#include <bits/stdc++.h>
#define h 1000000007
using namespace std;
long long fact[200005];
long long po(long long a, long long b)
{
    long long m;
    if(b==0) return 1;
    if(b==1) return a%h;
    if(b%2==0)
    {
        m=po(a,b/2);
        return (m*m)%h;
    }
    else
    {
        m=po(a,b/2);
        return ((m*m%h)*a)%h;
    }
}
long long ncr(long long n,long long r)
{
    if(n<r) return 0;
    return ((fact[n]*po(fact[r],h-2)%h)*po(fact[n-r],h-2))%h;
}
long long n,o[200005]={0},c[200005]={0},ans=0,i;
char a[200005];
int main()
{
    cin>>a;
    n=strlen(a);
    fact[0]=1;
    for(i=1;i<=n;++i)
    fact[i]=(i*fact[i-1])%h;

    o[0]=(a[0]=='(');
    for(i=1;i<n;++i)
    if(a[i]=='(') 
    o[i]=o[i-1]+1;
    else 
    o[i]=o[i-1];

    c[n-1]=(a[n-1]==')');
    for(i=n-2;i>=0;i--)
    if(a[i]==')') 
    c[i]=c[i+1]+1;
    else 
    c[i]=c[i+1];
    
    for(i=0;i<n;++i)
    if(a[i]=='(')
    { ans+=ncr(o[i-1]+c[i],c[i]-1);
      ans%=h; }
    cout<<ans;
    return 0;
}