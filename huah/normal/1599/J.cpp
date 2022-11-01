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
const int N=1e3+5,mod=1e9+7,low=15000000;
int n,a[N],b[N];
bool cmp(int x,int y){return (x&1)<(y&1);}
vector<int>vc;
int vis[30000005];
bool use[N];
void sol()
{
  int m=min(n,26),k=m/2;
  int x=-1,y=-1;
  for(int i=1;i<1<<m;i++)
    if(__builtin_popcount(i)==k)
    {
      int sum=0;
      for(int j=0;j<m;j++)
        if(i>>j&1) sum+=a[j+1];
      if(vis[sum+low])
      {
        x=vis[sum+low];y=i;
        break;
      }
      else vis[sum+low]=i;
    }
  if(x==-1&&y==-1)
  {
    printf("NO\n");return;
  }
  int u=x&y;
  x^=u;y^=u;
  vector<int>vc1,vc2;
  for(int i=0;i<m;i++)
  {
    if(x>>i&1) vc1.push_back(i+1),use[i+1]=true;
    if(y>>i&1) vc2.push_back(i+1),use[i+1]=true;
  }
  int len=vc1.size();
  b[1]=0;
  rep(i,2,len*2)
  {
    if(i%2==0) b[i]=a[vc1.back()]-b[i-1],vc1.pop_back();
    else b[i]=a[vc2.back()]-b[i-1],vc2.pop_back();
  }
  len*=2;
  rep(i,1,n)
    if(!use[i]) b[++len]=a[i];
  printf("YES\n");
  rep(i,1,n)
    printf(i==n?"%d\n":"%d ",b[i]);
}
ll c[N][N];
ll C(int n,int m)
{
  if(m==0||m==n) return 1;
  if(m==1) return n;
  if(c[n][m]) return c[n][m];
  return c[n][m]=(C(n-1,m-1)+C(n-1,m));
}
int main()
{
  // rep(n,1,1000)
  // {
  //   bool flag=false;
  //   rep(j,1,n/2)
  //   if(C(n,j)>=j*1000000)
  //   {
  //     cout<<n<<' '<<j<<endl;
  //     flag=true;break;
  //   }
  //   if(flag){cout<<n<<'\n';break;}
  // }
  // return 0;
  sc(n);
  rep(i,1,n) sc(a[i]);
  sort(a+1,a+1+n);
  rep(i,1,n-1)
    if(a[i]==a[i+1])
    {
      a[i]=0;
      printf("YES\n");
      rep(i,1,n)
        printf(i==n?"%d\n":"%d ",a[i]);
      return 0;
    }
  if(n==2){printf("NO\n");return 0;}
  if(n==3)
  {
    int y=a[1]-a[2]+a[3];
    if(y%2==0)
    {
      printf("YES\n");
      int x=y/2;
      printf("%d %d %d\n",x,a[2]-(a[3]-x),a[3]-x);
    }
    else printf("NO\n");
    return 0;
  }
  sort(a+1,a+1+n,cmp);
  if((a[1]&1)) sol();
  else
  {
    printf("YES\n");
    if((a[n]&1)&&(a[n-1])&1)
    {
      swap(a[n-1],a[2]);
      swap(a[n],a[3]);
    }
    int y=a[1]-a[2]+a[3];
    assert(y%2==0);
    b[1]=y/2;
    b[3]=a[3]-b[1];
    b[2]=a[2]-b[3];
    rep(i,4,n)
      b[i]=a[i]-b[1];
    rep(i,1,n) printf(i==n?"%d\n":"%d ",b[i]);
  }
}
/*
x1+x2=a[1]
x2+x3=a[2]
x3+x1=a[3]

x1+a[2]-(a[3]-x1)=a[1]
2x1=a[1]-a[2]+a[3]

befor submit code check:
freopen
size of N
mod
debug output
*/