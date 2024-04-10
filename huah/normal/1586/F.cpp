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
const int N=1005;
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
int n,k,mx,e[N][N];
void sol(int l,int r,int dep)
{
    if(l==r) return;
    mx=max(mx,dep);
    int len=(r-l+1)/k+((r-l+1)%k!=0);
    for(int i=l;i<=r;i+=len)
    {
        for(int j=l;j<i;j++)
            for(int k=i;k<=min(r,i+len-1);k++)
            e[j][k]=dep;
        sol(i,min(r,i+len-1),dep+1);
    }
}
int main()
{
    srand(time(0));
    // freopen("1.in","w",stdout);
    scanf("%d%d",&n,&k);
    sol(1,n,1);
    out(mx);
    rep(i,1,n)
        rep(j,i+1,n)
        printf(i==n&&j==n?"%d\n":"%d ",e[i][j]);
}