#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
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
void iary(int *a,int l,int r){rep(i,l,r)sc(a[i]);}
void iary(ll *a,int l,int r){rep(i,l,r)sc(a[i]);}
void oary(int *a,int l,int r){rep(i,l,r)printf(i==r?"%d\n":"%d ",a[i]);}
void oary(ll *a,int l,int r){rep(i,l,r)printf(i==r?"%lld\n":"%lld ",a[i]);}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=4e5+5,mod=1e9+7;
int n,a[N],b[N],f[N];
bool del[N];
void sol(int cas)
{
    sc(n);
    rep(i,1,n)
    {
      sc(a[i],b[i]);
      f[a[i]]=f[b[i]]=i;
    }
    int res=0;
    for(int l=1,r=2*n;l<r;)
    {
      int pos=f[l];
      if(del[pos])
      {
        printf("-1\n");return;
      }
      if(a[pos]==l&&b[pos]==r||a[pos]==r&&b[pos]==l)
      {
        del[pos]=true;
        l++;
        r--;
        continue;
      }
      deque<int>L,R;
      L.push_back(pos);
      int ans=0,len=0;
      if(a[pos]!=l) swap(a[pos],b[pos]),ans++;
      del[pos]=true;
      l++;
      len++;
      while(L.size()||R.size())
      {
        while(L.size())
        {
          while(r>b[L.front()])
          {
            if(del[f[r]])
            {
              printf("-1\n");return;
            }
            R.push_back(f[r]);
            len++;
            del[f[r]]=true;
            // cout<<"R: "<<r<<' '<<a[f[r]]<<' '<<b[f[r]]<<endl;
            if(a[f[r]]!=r) swap(a[f[r]],b[f[r]]),ans++;
            // ,cout<<"AD"<<' '<<ans<<endl;
            r--;
          }
          if(r==b[L.front()]) r--;
          L.pop_front();
        }
        while(R.size())
        {
          while(l<b[R.front()])
          {
            if(del[f[l]])
            {
              printf("-1\n");return;
            }
            L.push_back(f[l]);
            del[f[l]]=true;
            len++;
            // cout<<"L: "<<l<<' '<<a[f[l]]<<' '<<b[f[l]]<<endl;
            if(a[f[l]]!=l) swap(a[f[l]],b[f[l]]),ans++;
            // ,cout<<"AD"<<' '<<ans<<endl;
            l++;
          }
          if(l==b[R.front()]) l++;
          R.pop_front();
        }
      }
      res+=min(ans,len-ans);
      /*
      l l+1 ... l+y-1        r-x+1 ...  r-1 r
      r-x                                 l+y
      */
    }
    out(res);
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
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