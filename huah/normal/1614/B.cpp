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
mt19937_64 gen(time(0));
ll rdint(ll l,ll r){return uniform_int_distribution<ll>(l,r)(gen);}
const int N=1e6+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,b[N];
pair<int,int>a[N];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
      sc(n);
      rep(i,1,n) sc(a[i].first),a[i].second=i;
      sort(a+1,a+1+n);
      vector<int>v1,v2;
      reverse(a+1,a+1+n);
      ll ans=0;
      for(int i=1;i<=n;i++)
      {
        if(v1.size()<v2.size())
        {
          v1.push_back(a[i].second);
          b[a[i].second]=-v1.size();
          ans+=1ll*v1.size()*a[i].first;
        }
        else
        {
          v2.push_back(a[i].second);
          b[a[i].second]=v2.size();
          ans+=1ll*v2.size()*a[i].first;
        }
      }
      out(ans*2);
      rep(i,0,n)
        printf(i==n?"%d\n":"%d ",b[i]);
    }
}