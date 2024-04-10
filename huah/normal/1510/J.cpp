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
const int N=4e5+5,mod=998244353;
int n,p,g,vis[N];
char s[N];
vector<int>v,v2;
vector<int>ans;
void cal(int x)
{
  while(x>3)
  {
    ans.push_back(1);
    x-=2;
  }
  if(x==2) ans.push_back(1);
  else if(x==3) ans.push_back(2);
}
void sol(int cas)
{
  sc(s+1);
  n=strlen(s+1);
  bool flag=true;
  rep(i,1,n) if(s[i]=='#') flag=false;
  if(flag){out(0);return;}
  int t=0,pre=0;
  rep(i,1,n)
  {
    if(s[i]=='#')
    {
      if(t==0)
      {
        if(pre==0) p=i-pre-1;
        else v2.push_back(i-pre-1);
      }
      pre=i;
      t++;
    }
    else
    {
      if(t) v.push_back(t);
      t=0;
    }
  }
  g=n-pre;
  if(t) v.push_back(t);
  int mn=min(p,g);
  for(int x:v2) mn=min(mn,x-1),vis[x]++;
  for(int i=0;i<=mn;i++)
  {
    if(vis[i+2]) continue;
    if(p-i==1||g-i==1) continue;
    if(i==0&&(p!=0||g!=0||vis[1]!=v.size()-1)) continue;
    if(i==1)
    {
      bool flag=true;
      for(int x:v2) if((x-i-1)%2) flag=false;
      if((p-i)%2) flag=false;
      if((g-i)%2) flag=false;
      if(!flag) continue;
    }
    cal(p-i);
    for(int j=0;j<v.size();j++)
    {
      ans.push_back(v[j]+i);
      if(j==v.size()-1) cal(g-i);
      else cal(v2[j]-i-1);
    }
    // cout<<"I: "<<i<<' '<<v2[0]<<endl;
    printf("%d\n",int(ans.size()));
    for(int j=0;j<ans.size();j++)
      printf(j==ans.size()-1?"%d\n":"%d ",ans[j]);
    int sss=0;
    for(int x:ans) sss+=x;
    sss+=ans.size()-1;
    // cout<<n<<' '<<sss<<endl;
    assert(n-sss==i);
    return;
  }
  out(-1);
}
/*
__##________###__

__#_____
4
2 1 1 2
*/
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
a[1]_a[2]_a[3]--- reminder A empty cells
max(0,a[i]-A)

b[i]=max(0,a[i]-A)



*/
/*
befor submit code check:
freopen
size of N
mod
debug output
*/