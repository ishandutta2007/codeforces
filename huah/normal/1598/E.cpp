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
const int N=1005,mod=1e9+7;
int n,m,q;
ll dp[N][N][2];
bool del[N][N];
int getlen(int x,int y,int dx,int dy)
{
    int ans=1;
    x+=dx;y+=dy;
    swap(dx,dy);
    while(x>=1&&x<=n&&y>=1&&y<=m&&!del[x][y])
    {
        ans++;
        x+=dx;y+=dy;
        swap(dx,dy);
    }
    return ans;
}
ll getway(int x,int y)
{
    ll ans=0;
    int l=getlen(x,y,0,-1),r=getlen(x,y,1,0);
    ans+=l*r;
    l=getlen(x,y,-1,0),r=getlen(x,y,0,1);
    ans+=l*r;
    return ans-1;
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    sc(n,m,q);
    ll ans=0;
    rep(i,1,n)
        rep(j,1,m)
        {
            dp[i][j+1][0]++;
            dp[i+1][j][1]++;
            dp[i+1][j][1]+=dp[i][j][0];
            dp[i][j+1][0]+=dp[i][j][1];
            ans+=dp[i][j][0]+dp[i][j][1];
        }
    ans+=n*m;
    while(q--)
    {
        int x,y;sc(x,y);
        if(del[x][y]) ans+=getway(x,y);
        else ans-=getway(x,y);
        del[x][y]^=1;
        out(ans);
    }
}