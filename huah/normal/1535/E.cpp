#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f3f3f3f3fll
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
const int N=5e5+5,mod=998244353;
int q,dep[N],a[N],c[N],fa[N][20],lg[N];
int main()
{
    rep(i,1,N-1) lg[i]=lg[i-1]+(1<<lg[i-1]==i),lg[i-1]--;
    sc(q,a[1],c[1]);
    for(int i=2;i<=q+1;i++)
    {
        int op;sc(op);
        if(op==1)
        {
            sc(fa[i][0],a[i],c[i]);
            fa[i][0]++;
            dep[i]=dep[fa[i][0]]+1;
            for(int j=1;1<<j<=dep[i];j++)
                fa[i][j]=fa[fa[i][j-1]][j-1];
        }
        else
        {
            int v,w;sc(v,w);v++;
            ll ans=0,sum=0;
            while(w)
            {
                if(!a[v]) break;
                int u=v;
                for(int i=lg[dep[v]];i>=0;i--)
                    if(a[fa[u][i]]) u=fa[u][i];
                if(a[u]>=w) sum+=w,ans+=1ll*w*c[u],a[u]-=w,w=0;
                else
                {
                    sum+=a[u];
                    ans+=1ll*a[u]*c[u];
                    w-=a[u];
                    a[u]=0;
                }
            }
            out(sum,ans);
            fflush(stdout);
        }
    }
}