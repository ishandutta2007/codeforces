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
const int N=5e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,a[N];
int main()
{
  // freopen("1.in","r",stdin);
  int t=1;
  sc(t);
  while(t--)
  {
    sc(n);
    rep(i,1,n) sc(a[i]);
    /*
    a[1] ... a[n-1] a[n]
    a[n-1]<=(a[1]+a[n])/2
    a[n-1]*2<=a[1]+a[n]
    a[n]>=a[n-1]*2-a[1]
    */
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      int res=1;
      int k=i;
      while(k<n&&a[k+1]==a[i]) k++;
      res+=k-i;
      i=k;
      int j=i+1;
      while(j<=n&&a[n]>=a[j-1]*2-a[i])
      {
        res++;
        int l=j,r=n;
        while(l<r)
        {
          int m=(l+r)>>1;
          if(a[m]>=a[j-1]*2-a[i]) r=m;
          else l=m+1;
        }
        j=r+1;
      }
      ans=max(ans,res);
    }
    out(n-ans);
  }
}