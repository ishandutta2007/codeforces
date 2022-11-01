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
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=1e5+5,mod=998244353,bs=320;
#define inf 0x3f3f3f3f
int n,a[N],val[N],cur[N];
int f1[N][bs],f2[N][bs],g[N];
int query(int x,int y)
{
    if(y==a[x]) return g[x];
    if(y<bs) return f1[x][y];
    return f2[x][a[x+1]/y];
}
void add(int x,int y,int v)
{
    if(y==a[x]) g[x]=v;
    if(y<bs) f1[x][y]=v;
    else f2[x][a[x+1]/y]=v;
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;scanf("%d",&t);
    while(t--)
    {
        sc(n);
        rep(i,1,n) memset(f1[i],-1,sizeof(f1[i])),memset(f2[i],-1,sizeof(f2[i])),g[i]=-1;
        rep(i,1,n) sc(a[i]);
        a[n+1]=100000;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            int j=i;
            cur[i]=a[i];
            while(j&&query(j,cur[j])==-1)
            {
                val[j]=0;
                if(a[j]<=cur[j]) cur[j-1]=a[j];
                else
                {
                    int s=a[j]/cur[j];
                    if(a[j]%cur[j]) s++;
                    val[j]=(val[j]+1ll*(s-1)*j%mod);
                    cur[j-1]=a[j]/s;
                }
                j--;
            }
            val[j]=query(j,cur[j]);
            if(val[j]==-1) val[j]=0;
            while(j<i) j++,val[j]=(val[j-1]+val[j])%mod,add(j,cur[j],val[j]);
            ans=(ans+query(i,a[i]))%mod;
        }
        out(ans);
    }
}