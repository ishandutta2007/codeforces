#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
const int N=1e5+5,mod=1e9+7;
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
int n,a[N],res[N],tot,b[N];
vector<int>fac[N];
int vis[N],d[N],vd[N];
int sol(int n,int *a)
{
    vector<int>vc;
    for(int i=1;i<=n;i++)
        for(int x:fac[a[i]])
        {
            if(!vis[x]) vc.push_back(x);
            vis[x]+=vd[b[i]];
        }
    sort(vc.begin(),vc.end());
    reverse(vc.begin(),vc.end());
    int ans=0;
    for(int x:vc)
    {
        int sum=1ll*vis[x]*(vis[x]-1)/2%mod;
        sum=(sum+mod-d[x])%mod;
        for(int y:fac[x])
            if(y!=x) d[y]=(d[y]+sum)%mod;
        ans=(ans+1ll*sum*x%mod)%mod;
        vis[x]=d[x]=0;
    }
    return ans;
}
int main()
{
    for(int i=1;i<=100000;i++)
        for(int j=i;j<=100000;j+=i)
        fac[j].push_back(i);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    // n=100000;
    // for(int i=1;i<=n;i++) a[i]=83160;
    int ans=0;
    for(int d=n;d>=1;d--)
    {
        tot=0;
        for(int i=d;i<=n;i+=d)
        {
            if(!vd[a[i]]) b[++tot]=a[i];
            vd[a[i]]++;
        }
        res[d]=sol(tot,b);
        for(int i=d;i<=n;i+=d) vd[a[i]]=0;
        for(int i=d+d;i<=n;i+=d)
            res[d]=(res[d]+mod-res[i])%mod;
        ans=(ans+1ll*d*res[d])%mod;
    }
    ans=ans*2%mod;
    for(int i=1;i<=n;i++)
        ans=(ans+1ll*a[i]*i%mod)%mod;
    // int res=0;
    // for(int i=1;i<=n;i++)
    //     for(int j=i+1;j<=n;j++)
    //     if(__gcd(i,j)==1) res+=__gcd(a[i],a[j]);
    // printf("%d\n",res);
    printf("%d\n",ans);
}