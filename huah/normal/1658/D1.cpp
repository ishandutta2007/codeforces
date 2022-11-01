#pragma GCC optimize(2)
#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define nep(i,r,l) for(int i=r;i>=l;--i)
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
const int N=2e5+5,mod1=1e9+7,mod=998244353;
#define inf 0x3f3f3f3f
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
      vector<int>vis1(17),vis2(17);
      int l,r;sc(l,r);
      vector<int>a(r-l+1);
      for(int i=l;i<=r;++i)
      {
        int x;sc(x);a[i-l]=x;
        for(int j=0;j<17;++j)
        { 
          if(i>>j&1) ++vis1[j];
          if(x>>j&1) ++vis2[j];
        }
      }
      int ans=0;
      vector<int>vc;
      for(int i=0;i<17;++i) 
      if(vis1[i]!=vis2[i]) ans|=1<<i;
      else if(vis1[i]==r-l+1-vis1[i]) vc.push_back(i);
      function<bool(int,int,int,vector<int>&)>judge=[&](int x,int l,int r,vector<int>&b)
      {
        auto a=b;
        for(int &val:a) val^=x;
        sort(a.begin(),a.end());
        for(int i=0,j=l;i<int(a.size());++i,++j)
          if(a[i]!=j) return false;
        return true;
      };
      int si=vc.size();
      for(int i=0;i<1<<si;++i)
      {
        int ret=ans;
        for(int j=0;j<si;++j)
          if(i>>j&1) ret|=1<<vc[j];
        if(judge(ret,l,r,a))
        {
          out(ret);break;
        }
      }
    }
}