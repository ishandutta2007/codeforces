#include <bits/stdc++.h>
#define pb push_back
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int v[26],i,f[1000006],in[1000006],h=1e9+7,n;
long long temp;
string a,b;
int po(int a,int b)
{
    if(a==0) return 0;
    if(a==1 || b==0) return 1;
    int ans=1;
    while(b)
    {
        if(b&1) ans=(1LL*ans*a)%h;
        a=(1LL*a*a)%h;
        b>>=1;
    }
    return ans;
}
void pre()
{
    int i;
    f[0]=1;
    for(i=1;i<=1e6;++i)
    f[i]=(1LL*i*f[i-1])%h;
    i--;
    in[i]=po(f[i],h-2);
    while(i--)
    in[i]=(1LL*(i+1)*in[i+1])%h;
}
int solve(int x, int f1, int f2, int cur)
{
    if(x==n) return !f1 && !f2;
    int i,ans=0;
    if(f1==0 && f2==0) return cur;
    if(f1==0 && f2==1)
    {
        for(i=0;i<=b[x]-'a';++i)
        if(v[i])
        {
            temp=(1LL*cur*f[v[i]])%h;
            temp=(temp*in[--v[i]])%h;
            temp=(temp*in[n-x])%h;
            temp=(temp*f[n-x-1])%h;
            ans=(ans+solve(x+1,0,i==(b[x]-'a'),temp))%h;
            ++v[i];
        }
    }
    else if(f1==1 && f2==0)
    {
        for(i=a[x]-'a';i<26;++i)
        if(v[i])
        {
            temp=(1LL*cur*f[v[i]])%h;
            temp=(temp*in[--v[i]])%h;
            temp=(temp*in[n-x])%h;
            temp=(temp*f[n-x-1])%h;
            ans=(ans+solve(x+1,i==(a[x]-'a'),0,temp))%h;
            ++v[i];
        }
    }
    else
    {
        for(i=a[x]-'a';i<=b[x]-'a';++i)
        if(v[i])
        {
            temp=(1LL*cur*f[v[i]])%h;
            temp=(temp*in[--v[i]])%h;
            temp=(temp*in[n-x])%h;
            temp=(temp*f[n-x-1])%h;
            ans=(ans+solve(x+1,i==(a[x]-'a'),i==(b[x]-'a'),temp))%h;
            ++v[i];
        }
    }
    return ans;
}
int main()
{
    io
    pre();
    cin>>a>>b;
    n=a.size();
    for(i=0;i<n;++i)
    v[a[i]-'a']++;
    int cur=f[n];
    for(i=0;i<26;++i)
    cur=(1LL*cur*in[v[i]])%h;
    cout<<solve(0,1,1,cur);
    return 0;
}