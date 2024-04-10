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
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=45;
bool dp[N][N][N][N];
int pj[N][N][N][N],pk[N][N][N][N],ph[N][N][N][N];
int n,a,b;
char s[N];
void sol(int cas)
{
  memset(dp,false,sizeof(dp));
  sc(n,a,b);
  sc(s+1);
  dp[0][0][0][0]=true;
  for(int i=0;i<n;i++)
    for(int j=0;j<a;j++)
      for(int k=0;k<b;k++)
      for(int h=0;h<=i;h++)
      if(dp[i][j][k][h])
      {
        dp[i+1][(j*10+s[i+1]-'0')%a][k][h+1]=true;
        pj[i+1][(j*10+s[i+1]-'0')%a][k][h+1]=j;
        pk[i+1][(j*10+s[i+1]-'0')%a][k][h+1]=k;
        ph[i+1][(j*10+s[i+1]-'0')%a][k][h+1]=h;
        dp[i+1][j][(k*10+s[i+1]-'0')%b][h]=true;
        pj[i+1][j][(k*10+s[i+1]-'0')%b][h]=j;
        pk[i+1][j][(k*10+s[i+1]-'0')%b][h]=k;
        ph[i+1][j][(k*10+s[i+1]-'0')%b][h]=h;
      }
    int jj=0,kk=0,hh,mn=9999;
    for(int h=1;h<n;h++)
      if(dp[n][0][0][h]&&abs(h-(n-h))<mn)
      mn=abs(h-(n-h)),hh=h;
    if(mn==9999){out(-1);return;}
    string ans;
    for(int i=n;i>=1;i--)
    {
      int nj=pj[i][jj][kk][hh],nk=pk[i][jj][kk][hh],nh=ph[i][jj][kk][hh];
      if(nh<hh) ans+='R';
      else ans+='B';
      jj=nj;kk=nk;hh=nh;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
}
int main()
{
  // freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
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