#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
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
using namespace std;
const int N=1e5+5,mod=1e9+7;
bitset<100001>dp,g;
int n,m,ans[N];
int main()
{
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    sc(n,m);
    dp[0]=1;
    rep(i,1,n)
    {
        int t,y;
        ll x;
        sc(t);sc(x);sc(y);
        if(t==1)
        {
            x=x/100000+(x%100000!=0);
            for(int j=1;y>=j;j<<=1)
                dp=dp|(dp<<(j*x)),y-=j;
            dp|=dp<<(y*x);
        }
        else
        {
            nep(j,m,1)
            if(dp[j])
            {
                ll s=j;
                rep(k,1,y)
                {
                    ll t=s*x/100000+(s*x%100000!=0);
                    if(t>m||dp[t]) break;
                    dp[t]=1;
                    s=t;
                }
            }
        }
        rep(j,1,m)
        if(dp[j]&&!ans[j]) ans[j]=i;
    }
    rep(i,1,m) ans[i]=ans[i]?ans[i]:-1;
    rep(i,1,m) printf(i==m?"%d\n":"%d ",ans[i]);
}