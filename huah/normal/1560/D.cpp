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
int n;
int cal(ll x,ll y)
{
  vector<int>v1,v2;
  if(x==0) v1.push_back(0);
  if(y==0) v2.push_back(0);
  while(x) v1.push_back(x%10),x/=10;
  while(y) v2.push_back(y%10),y/=10;
  reverse(v1.begin(),v1.end());
  int ans=v1.size();
  for(int x:v1)
    if(!v2.empty()&&v2.back()==x)
    {
      v2.pop_back();
      ans--;
    }
  return ans+int(v2.size());
}
int main()
{
  // freopen("1.in","r",stdin);
    int t;sc(t);
    while(t--)
    {
      sc(n);
      int ans=1e9;
      for(int i=0;i<61;i++)
        ans=min(ans,cal(n,1ll<<i));
      out(ans);
    }
}