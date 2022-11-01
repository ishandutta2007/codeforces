#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
const int N=105;
int n,m,k,p,fac[N];
int c[N][N];
/*
f[n][m][k]=f[w-1][m-1][]*f[n-w][m-1][]
*/
int f[N][N][N];
void add(int &x,int y){x+=y;if(x>=p) x-=p;}
void sol(int cas)
{
    sc(n,m,k);sc(p);
    fac[0]=1%p;
    rep(i,1,n) fac[i]=1ll*fac[i-1]*i%p;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i;j++)
        if(j==0||j==i) c[i][j]=1%p;
        else c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
    for(int i=0;i<=n;i++) f[0][i][0]=1%p;
    for(int i=1;i<=n;i++)
    {
        f[i][1][1]=fac[i];
        for(int j=i+1;j<=n;j++) f[i][j][0]=fac[i];
        for(int j=2;j<=i;j++)
        for(int k=0;k<=i-j+1;k++)
        {
            add(f[i][j][k],f[i-1][j-1][k-(j==1)]*2%p);
            for(int a=2;a<i;a++)
                for(int b=0;b+(j==1)<=k;b++)
                if(f[a-1][j-1][b]&&f[i-a][j-1][k-b-(j==1)])
                add(f[i][j][k],1ll*c[i-1][a-1]*f[a-1][j-1][b]%p*f[i-a][j-1][k-b-(j==1)]%p);
        }
    }
    out(f[n][m][k]);
}
int main() 
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
}