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
const int N=2e5+5,mod=998244353,G=3,Gi=332748118;
int n,k,l[11],b[11][41];
ll g[44],bb[11],bbb[11][41],all;
unordered_map<ll,bool>ok;
void dfs(ll a,int op,ll st)
{
  if(op==k+1)
  {
    if(!ok.count(st))
    {
      printf("REJECTED\n");
      exit(0); 
    }
    return;
  }
  int c0=__builtin_popcountll((all^a)&(all^st)&bb[op]),cx=__builtin_popcountll(a&bb[op]);
  a=a^(a&bb[op]);
  st=(st^(st&bb[op]))|bbb[op][c0];
  for(int i=0;i<=cx;i++)
  {
    if(i)
      st^=g[b[op][c0+i-1]];
    dfs(a,op+1,st);
  }
}
bool vis[45];
void sol(int cas)
{
  // DWORD begin=GetTickCount();
  sc(n,k);
  rep(i,1,k)
  {
    sc(l[i]);
    rep(j,0,l[i]-1) sc(b[i][j]),b[i][j]--,vis[b[i][j]]=true,bb[i]|=1ll<<b[i][j];
    bbb[i][0]=bb[i];
    for(int j=1;j<=l[i];j++)
        bbb[i][j]=bbb[i][j-1]^(1ll<<b[i][j-1]);
  }
  if(n==1)
  {
    printf("ACCEPTED\n");
    return;
  }
  rep(i,0,n-1) if(!vis[i]){printf("REJECTED\n");return;}
  vector<int>a;
  rep(i,1,n) a.push_back(-1);
  g[0]=1;
  rep(i,1,n-1) g[i]=g[i-1]*2;
  ll st=1ll<<n;
  st--;
  all=st;
  ok[st]=true;
  while(st)
  {
    st^=st&-st;
    ok[st]=true;
  }
  dfs((1ll<<n)-1,1,0);
  printf("ACCEPTED\n");
  // DWORD en=GetTickCount();
  // cout<<en-begin<<"ms"<<endl;
}
int main()
{
//   freopen("1.in", "r",stdin);
  // freopen("2.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  // scanf("%d",&t);
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