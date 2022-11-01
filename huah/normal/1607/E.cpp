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
const int N=2e6+5,mod=1e9+7,bs=320;
#define inf 0x3f3f3f3f
int n,m;
char s[N];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n,m);sc(s+1);
        int k=strlen(s+1);
        int x=0,y=0,mnx=0,mxx=0,mny=0,mxy=0;
        rep(i,1,k)
        {
            int nx=x,ny=y;
            if(s[i]=='L') ny--;
            else if(s[i]=='R') ny++;
            else if(s[i]=='U') nx--;
            else nx++;
            int nmnx=mnx,nmxx=mxx,nmny=mny,nmxy=mxy;
            nmnx=min(nmnx,nx);
            nmxx=max(nmxx,nx);
            nmny=min(nmny,ny);
            nmxy=max(nmxy,ny);
            if(nmxx-nmnx+1>n||nmxy-nmny+1>m) break;
            mnx=nmnx;
            mxx=nmxx;
            mny=nmny;
            mxy=nmxy;
            x=nx;
            y=ny;
        }
        out(-mnx+1,-mny+1);
    }
}