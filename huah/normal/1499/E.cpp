#pragma GCC optimize(2)
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
const int N=1005,mod=998244353;
int f[N][N][2][2][2];
char s[N],t[N];
int n,m;
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int main()
{
  sc(s+1);
  sc(t+1);
  n=strlen(s+1);m=strlen(t+1);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
      add(f[i+1][j][0][1][0],1);
      add(f[i][j+1][1][0][1],1);
    }
  for(int i=1;i<=n+1;i++)
    for(int j=1;j<=m+1;j++)
    for(int k=0;k<=1;k++)
    for(int h=0;h<=1;h++)
      for(int g=0;g<=1;g++)
    if(f[i][j][k])
    {
      char las=s[i-1];
      if(k==1) las=t[j-1];
      if(i<=n&&s[i]!=las)
        add(f[i+1][j][0][1][g],f[i][j][k][h][g]);
      if(j<=m&&t[j]!=las)
        add(f[i][j+1][1][h][1],f[i][j][k][h][g]);
    }
  int ans=0;
  for(int i=1;i<=n+1;i++)
    for(int j=1;j<=m+1;j++)
    add(ans,f[i][j][0][1][1]),add(ans,f[i][j][1][1][1]);
  out(ans);
}