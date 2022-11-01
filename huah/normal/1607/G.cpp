#include<bits/stdc++.h>
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
const int N=2e5+5,mod=1e6+5;
#define inf 0x3f3f3f3f
int n,m,a[N],b[N],c[N],d[N];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n);
        sc(m);
        rep(i,1,n) sc(a[i],b[i]),c[i]=d[i]=0;
        ll sa=0,sb=0;
        rep(i,1,n)
        {
            int t=min(a[i],m);
            a[i]-=t;
            c[i]+=t;
            t=m-t;
            b[i]-=t;
            d[i]+=t;
            sa+=a[i];
            sb+=b[i];
        }
        if(sb>sa)
        {
            rep(i,1,n)
            {
                ll t=(sb-sa)/2;
                t=min(t,1ll*min(c[i],b[i]));
                sa+=t;
                sb-=t;
                c[i]-=t;
                d[i]+=t;
                a[i]+=t;
                b[i]-=t;
            }
        }
        out(abs(sa-sb));
        rep(i,1,n) out(c[i],d[i]);
    }
}