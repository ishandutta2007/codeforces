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
int n,a[N],b[N],c[N];
int d[]={0,1,6,4,2,3,5,4};
int query(string s,int x,int y)
{
  // if(s=="or") return d[x]|d[y];
  // return d[x]&d[y];
  cout<<s<<' '<<x<<' '<<y<<'\n';
  fflush(stdout);
  int ans;scanf("%d",&ans);
  return ans;
}
int main()
{
  // freopen("1.in","r",stdin);
    int t=1;
    // sc(t);
    while(t--)
    {
      int n,k;sc(n,k);
      for(int i=1;i<n;i++)
      {
        a[i]=0;
        b[i]=query("or",i,i+1);
        c[i]=query("and",i,i+1);
      }
      int x=query("or",1,3);
      int y=query("and",1,3);
      for(int i=0;i<30;i++)
      {
        int i1=b[1]>>i&1,i2=b[2]>>i&1,i3=x>>i&1;
        int j1=c[1]>>i&1,j2=c[2]>>i&1,j3=y>>i&1;
        bool flag=true;
        for(int k1=0;k1<=1&&flag;k1++)
          for(int k2=0;k2<=1&&flag;k2++)
          for(int k3=0;k3<=1&&flag;k3++)
          {
            if((k1|k2)==i1&&(k2|k3)==i2&&(k3|k1)==i3&&(k1&k2)==j1&&(k2&k3)==j2&&(k3&k1)==j3)
            {
              flag=false;
              if(k1) a[1]|=1<<i;
              if(k2) a[2]|=1<<i;
              if(k3) a[3]|=1<<i;
            }
          }
      }
      // cout<<a[1]<<' '<<a[2]<<' '<<a[3]<<endl;
      for(int i=4;i<=n;i++)
      {
        for(int j=0;j<30;j++)
          if(!(b[i-1]>>j&1));
          else if(c[i-1]>>j&1) a[i]|=1<<j;
          else if(!(a[i-1]>>j&1)) a[i]|=1<<j;
      }
      sort(a+1,a+1+n);
      printf("finish %d\n",a[k]);
      fflush(stdout);
    }
}
/*
7 2 5
0 4 0
*/