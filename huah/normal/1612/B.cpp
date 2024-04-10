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
const int N=3e5+5,mod1=1e9+7,mod2=998244353;
#define inf 0x3f3f3f3f
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;
    sc(t);
    while(t--)
    {
      int n,a,b;
      sc(n,a,b);
      if(a==b||a>b+1){printf("-1\n");continue;}
      vector<int>v1,v2;
      for(int i=b+1;i<=n;i++)
        if(i!=a) v1.push_back(i);
      for(int i=1;i<a;i++)
        if(i!=b) v2.push_back(i);
      int l=a+1,r=b-1;
      v1.push_back(a);
      v2.push_back(b);
      if(v1.size()>n/2||v2.size()>n/2)
      {
        printf("-1\n");continue;
      }
      for(int i=l;i<=r;i++)
        if(v1.size()<n/2) v1.push_back(i);
        else v2.push_back(i);
      for(int x:v1) printf("%d ",x);
      for(int i=0;i<v2.size();i++)
        printf(i==v2.size()-1?"%d\n":"%d ",v2[i]);
    }
}