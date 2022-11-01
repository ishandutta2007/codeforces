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
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=5e5+5,mod=1e9+7;
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  int t=1;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    vector<pair<int,int>>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++) sc(a[i].first),a[i].second=i;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++) b[a[i].second]=i;
    vector<tuple<int,int,int>>ans;
    for(int i=0;i<n;i++)
      if(b[i]!=i)
      {
        for(int j=i+1;j<n;j++)
          if(b[j]==i)
          {
            ans.push_back({i+1,j+1,j-i});
            for(int k=j;k>i;k--) b[k]=b[k-1];
            b[i]=i;
            break;
          }
      }
    printf("%d\n",int(ans.size()));
    for(auto x:ans)
      printf("%d %d %d\n",get<0>(x),get<1>(x),get<2>(x));
  }
}
/*
p1 p2 p3 p4 p5
*/