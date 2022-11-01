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
const int N=3e5+5,mod=998244353;
int n,k;
map<string,vector<int>>mp;
void sol(int cas)
{ 
  sc(n,k);
  ast(n,1,100000);
  ast(k,1,100000);
  ast(n*k,1,1000000);
  rep(i,1,n)
  {
    string s;
    int v;
    cin>>s>>v;
    mp[s].push_back(v);
  }
  ll ans=0,mx=0;
  for(auto it=mp.begin();it!=mp.end();it++)
  {
    string s=it->first;
    string t=s;
    reverse(t.begin(),t.end());
    if(s==t)
    {
      vector<int>&vc=mp[s];
      sort(vc.begin(),vc.end());
      while(vc.size()>=2)
      {
        ll x=vc.back();vc.pop_back();
        ll y=vc.back();vc.pop_back();
        if(y>=0) ans+=x+y;
        else if(x+y>0) 
        {
          ans+=x+y;
          mx=max(mx,-y);
        }
        else mx=max(mx,x);
      }
      if(vc.size()) mx=max(mx,1ll*vc[0]);
      vc.clear();
    }
    else
    {
      vector<int>&v1=mp[s],v2=mp[t];
      sort(v1.begin(),v1.end());
      sort(v2.begin(),v2.end());
      while(v1.size()&&v2.size())
      {
        ans+=max(0,v1.back()+v2.back());
        v1.pop_back();
        v2.pop_back();
      }
      v1.clear();v2.clear();
    }
  }
  out(ans+mx);
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  // scanf("%d",&t);
  ast(t,1,10);
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