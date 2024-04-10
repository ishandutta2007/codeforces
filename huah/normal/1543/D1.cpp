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
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;
int n,k,origin,cur;
int query(int x)
{
  // if(x==cur) return 1;
  // vector<int>v1,v2;
  // while(x) v1.push_back(x%k),x/=k;
  // while(cur) v2.push_back(cur%k),cur/=k;
  // while(v1.size()!=v2.size())
  // {
  //   if(v1.size()<v2.size()) v1.push_back(0);
  //   else v2.push_back(0);
  // }
  // for(int i=v2.size()-1;i>=0;i--)
  // {
  //   cur=cur*k+(v1[i]-v2[i]+k)%k;
  // }
  // return 0;
  printf("%d\n",x);
  fflush(stdout);
  int ans=0;scanf("%d",&ans);return ans;
}
void sol(int cas)
{
  // printf("Case #%d: ",cas);
  sc(n,k);
  origin=cur=rand()%n;
  int m=n;
  vector<int>v;
  while(m) v.push_back(0),m/=k;
  for(int x=0;x<n;x++)
  {
    for(int j=0;j<v.size();j++) v[j]=(k-v[j])%k;
    vector<int>s;
    m=x;
    while(m) s.push_back(m%k),m/=k;
    while(s.size()<v.size()) s.push_back(0);
    int ans=0;
    for(int j=s.size()-1;j>=0;j--)
    {
      int tmp;
      if(x&1) s[j]=(v[j]+s[j]+k)%k;
      else s[j]=(v[j]-s[j]+k)%k;
      ans=ans*k+s[j];
      v[j]=(v[j]-s[j]+k)%k;
    }
    if(query(ans)==1)
    {
      // cout<<x<<' '<<origin<<' '<<cur<<' '<<ans<<endl;
      break;
    }
  }
}
int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);
  int t,cas=0;scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
}