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
const int N=1005,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,m,f[N*N],si[N*N];
int id(int i,int j){return (i-1)*m+j;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    sc(n,m);
    rep(i,1,n*m) f[i]=i;
    rep(i,1,n)
      rep(j,1,m)
      {
        int x;sc(x);
        int l=x&1;
        x>>=1;
        int d=x&1;
        x>>=1;
        int r=x&1;
        x>>=1;
        int u=x;
        if(l==0) f[getf(id(i,j))]=getf(id(i,j-1));
        if(r==0) f[getf(id(i,j))]=getf(id(i,j+1));
        if(u==0) f[getf(id(i,j))]=getf(id(i-1,j));
        if(d==0) f[getf(id(i,j))]=getf(id(i+1,j));
      }
    rep(i,1,n*m) si[getf(i)]++;
    vector<int>ans;
    rep(i,1,n*m) if(f[i]==i) ans.push_back(si[i]);
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
}