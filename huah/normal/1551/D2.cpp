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
const int N=105,mod=1e9+7;
int n,m,k;
char ans[N][N];
bool vis[26];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void Fill(int x1,int y1,int x2,int y2)
{
  memset(vis,false,sizeof(vis));
  for(int i=0;i<4;i++)
  {
    int x=x1+dx[i];
    int y=y1+dy[i];
    if(ans[x][y]!='#') vis[ans[x][y]-'a']=true;
    x=x2+dx[i];
    y=y2+dy[i];
    if(ans[x][y]!='#') vis[ans[x][y]-'a']=true;
  }
  int j=0;
  while(vis[j]) j++;
  ans[x1][y1]=ans[x2][y2]=j+'a';
}
void sol(int cas)
{
  sc(n,m,k);
  rep(i,0,n+1)
    rep(j,0,m+1) ans[i][j]='#';
  if(n%2==0&&m%2==0)
  {
    if(k<=n*m/2&&k%2==0)
    {
      printf("YES\n");
      for(int j=1;j<=m;j+=2)
      {
        for(int i=1;i<=n;i+=2)
        {
          if(k)
          {
            k-=2;
            Fill(i,j,i,j+1);
            Fill(i+1,j,i+1,j+1);
          }
          else
          {
            Fill(i,j,i+1,j);
            Fill(i,j+1,i+1,j+1);
          }
        }
      }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        putchar(ans[i][j]);
        putchar('\n');
      }
    }
    else printf("NO\n");
  }
  else if(n%2==0)
  {
    if(k<=n*(m-1)/2&&k%2==0)
    {
      printf("YES\n");
      for(int i=1,j=0;i<=n;i+=2,j=(j+1)%26)
        ans[i][m]=ans[i+1][m]=j+'a';
      for(int j=1;j<=m-1;j+=2)
      {
        for(int i=1;i<=n;i+=2)
        {
          if(k)
          {
            k-=2;
            Fill(i,j,i,j+1);
            Fill(i+1,j,i+1,j+1);
          }
          else
          {
            Fill(i,j,i+1,j);
            Fill(i,j+1,i+1,j+1);
          }
        }
      }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        putchar(ans[i][j]);
        putchar('\n');
      }
    }
    else printf("NO\n");
  }
  else
  {
    k-=m/2;
    if(k>=0&&k%2==0&&k<=(n-1)*m/2)
    { 
      printf("YES\n");
      for(int i=1,j=0;i<=m;i+=2,j=(j+1)%26)
        ans[n][i]=ans[n][i+1]=j+'a';
      for(int j=1;j<=m;j+=2)
      {
        for(int i=1;i<=n-1;i+=2)
        {
          if(k)
          {
            k-=2;
            Fill(i,j,i,j+1);
            Fill(i+1,j,i+1,j+1);
          }
          else
          {
            Fill(i,j,i+1,j);
            Fill(i,j+1,i+1,j+1);
          }
        }
      }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
        putchar(ans[i][j]);
        putchar('\n');
      }
    }
    else printf("NO\n");
  }
}
int main() 
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/