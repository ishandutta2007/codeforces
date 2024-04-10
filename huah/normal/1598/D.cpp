#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
void ary(int *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void ary(ll *a,int n){for(int i=1;i<=n;i++) sc(a[i]);}
void oary(int *a,int n){rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);}
void oary(ll *a,int n){rep(i,1,n) printf(i==n?"%lld\n":"%lld ",a[i]);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
const int N=2e5+5,mod=1e9+7;
int n,vis[N];
pair<int,int>a[N];
/*
a1 a2 ... an
b1 b2 ... bn

ai diff + bi diff - (ai&bi)diff

---- ---- ---- ----

if 
ai = aj

b1!= b2 n-(ctb1+ctb2)
*/
ll C3(ll n){return n*(n-1)*(n-2)/6;}
ll cal(vector<int>&vc)
{
    if(vc.size()<=1) return 0;
    //n-vc.size()-c[i]-c[j]+2
    ll ans=1ll*(n+2-vc.size())*(1ll*vc.size()*(vc.size()-1)/2);
    ll sum=0;
    for(int x:vc) sum+=1ll*x*(vc.size()-1);
    return ans-sum;
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n);
        rep(i,1,n) vis[i]=0;
        rep(i,1,n) sc(a[i].first,a[i].second),vis[a[i].second]++;
        sort(a+1,a+1+n);
        ll dp[4];memset(dp,0,sizeof(dp));
        dp[0]=1;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            int j=i;
            while(j<n&&a[j+1].first==a[j].first) j++;
            dp[3]+=dp[2]*(j-i+1);
            dp[2]+=dp[1]*(j-i+1);
            dp[1]+=dp[0]*(j-i+1);
            ans+=C3(j-i+1);
            vector<int>vc;
            rep(k,i,j) vc.push_back(vis[a[k].second]);
            ans+=cal(vc);
            i=j;
        }
        out(ans+dp[3]);
    }
}
/*
2
4
2 4
3 4
2 1
1 3
5
1 5
2 4
3 3
4 2
5 1
*/