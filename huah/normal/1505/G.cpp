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
const int N=5e5+5,mod=998244353;
#define inf 0x3f3f3f3f
int f[]={10010,11020,20011,21012,11011,21021,22022,12021,11011,12012,10120,11130,20121,21122,11121,21131,22132,12131,11121,12122,10221,11231,12113,20222,21223,11222};
char g[666666];
int main()
{
  // freopen("1.in","r",stdin);
  for(int i=0;i<26;i++)
    if(!g[f[i]]) g[f[i]]=i+'a';
  int n;sc(n);
  while(n--)
  {
    int x=0;
    for(int i=0;i<5;i++){int y;sc(y);x=x*10+y;}
    putchar(g[x]);
  }
  putchar('\n');
}