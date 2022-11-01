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
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
const int N=3e5+5,mod=998244353;
int n,m,a[N],l[N],r[N];
const ll inf=1e18;
vector<pair<int,int>>vc,seg;
bool cmp(pair<int,int>&x,pair<int,int>&y)
{
	if(x.first!=y.first) return x.first<y.first;
	return x.second>y.second;
}
vector<pair<int,ll>>dp[N];
vector<ll>pre[N],bk[N];
void sol(int cas)
{
	sc(n,m);
	rep(i,1,n) sc(a[i]);
	sort(a+1,a+1+n);
	vc.clear();
	rep(i,1,m)
	{
		int l,r;sc(l,r);
		int pos=lower_bound(a+1,a+1+n,l)-a;
		if(!(pos<=n&&a[pos]<=r))
			vc.push_back({l,r});
	}
  if(vc.size()==0){out(0);return;}
	sort(vc.begin(),vc.end(),cmp);
	seg.clear();
	for(int i=0;i<vc.size();i++)
	{
		while(seg.size()&&seg.back().second>=vc[i].second) seg.pop_back();
		seg.push_back(vc[i]);
	}
	rep(i,0,n) dp[i].clear(),pre[i].clear(),bk[i].clear();
  a[n+1]=1e9+1;
  a[0]=-1e9-1;
  dp[0].push_back({0,0});
  pre[0].push_back(max(0,a[1]-seg[0].second));
  bk[0].push_back(max(0,a[1]-seg[0].second)*2);
  int j=0;
  while(j<seg.size()&&seg[j].first>a[0]&&seg[j].second<a[1]) j++;
  for(int i=1;i<=n;i++)
  {
    dp[i].push_back({j,inf});
    pre[i].push_back(inf);
    bk[i].push_back(inf);
    while(j<seg.size()&&seg[j].first>a[i]&&seg[j].second<a[i+1])
    {
      j++;
      dp[i].push_back({j,inf});
      pre[i].push_back(inf);
      bk[i].push_back(inf);
    }
  }
  for(int i=1;i<=n;i++)
  {
      for(int j=0,k=dp[i-1].size()-1;j<dp[i].size();j++)
      {
        pair<int,ll> &y=dp[i][j];
        int d=y.first?max(0,seg[y.first-1].first-a[i]):0;
        while(k>=0&&(dp[i-1][k].first<seg.size()?max(0,a[i]-seg[dp[i-1][k].first].second):0)<=d) k--;
        if(k>=0) y.second=min(y.second,pre[i-1][k]+2ll*d);
        if(k+1<dp[i-1].size()) y.second=min(y.second,bk[i-1][k+1]+d);
        int s=(y.first<seg.size()?max(0,a[i+1]-seg[y.first].second):0);
        pre[i][j]=dp[i][j].second+s;
        bk[i][j]=dp[i][j].second+s*2ll;
        if(j) pre[i][j]=min(pre[i][j],pre[i][j-1]);
      }
      for(int j=dp[i].size()-2;j>=0;j--) bk[i][j]=min(bk[i][j],bk[i][j+1]);
  }
  out(dp[n].back().second);
}
int main()
{
  // freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
  return 0;
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/