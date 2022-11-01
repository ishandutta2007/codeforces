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
const int N=5e5+5,mod1=1e9+7,mod2=998244353;
#define inf 0x3f3f3f3f
char s[N];
int n,m;
struct node
{
  int x,id;
  bool operator<(const node&o)const
  {
    if(x==o.x) return id>o.id;
    return x<o.x;
  }
}a[N];
int pos[N];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
      sc(n,m);
      for(int i=1;i<=n*m;i++) sc(a[i].x),a[i].id=i;
      sort(a+1,a+1+n*m);
      bool vis[n+1][m+1];memset(vis,false,sizeof(vis));
      int ans=0;
      for(int i=1;i<=n*m;i++) pos[a[i].id]=i;
      for(int i=1;i<=n*m;i++)
      {
        int x=(pos[i]-1)/m+1,y=(pos[i]-1)%m+1;
        vis[x][y]=true;
        for(int j=1;j<y;j++) ans+=vis[x][j];
      }
      out(ans);
    }
}