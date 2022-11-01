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
const int N=2e5+5,mod=998244353;
int n,m,k;
unordered_map<int,bool>vx,vy;
vector<int>vcx,vcy;
vector<pair<int,int>>vc1,vc2;
bool cmp(pair<int,int>&x,pair<int,int>&y)
{
	return x.second<y.second;
}
unordered_map<int,int>vis;
ll cal(vector<pair<int,int>>&vc,vector<int>&vcy)
{
	vis.clear();
	sort(vc.begin(),vc.end(),cmp);
	int i=0,j=0;
	ll ans=0;
	for(int k=0;k<vc.size();k++)
	{
		pair<int,int>&x=vc[k];
		while(j<vcy.size()&&vcy[j]<x.second) j++;
		if(j)
		{
			while(i<k&&vc[i].second<=vcy[j-1])
			{
				vis[vc[i].first]--;
				i++;
			}
		}
		ans+=k-i-vis[x.first];
		vis[x.first]++;
	}
	return ans;
}
void sol(int cas)
{
	sc(n,m,k);
	vx.clear();vy.clear();
	vcx.clear();vcy.clear();
	rep(i,1,n)
	{
		int x;sc(x);vx[x]=true;
		vcx.push_back(x);
	}
	rep(i,1,m)
	{
		int y;sc(y);vy[y]=true;
		vcy.push_back(y);
	}
	sort(vcx.begin(),vcx.end());
	sort(vcy.begin(),vcy.end());
	vc1.clear();
	vc2.clear();
	rep(i,1,k)
	{
		int x,y;sc(x,y);
		if(vx.count(x)&&vy.count(y)) continue;
		if(vx.count(x)) vc1.push_back({x,y});
		else assert(vy.count(y)),vc2.push_back({y,x});
	}
	ll ans=cal(vc1,vcy);
	ans+=cal(vc2,vcx);
	out(ans);
}
int main()
{
//   freopen("1.in", "r",stdin);
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