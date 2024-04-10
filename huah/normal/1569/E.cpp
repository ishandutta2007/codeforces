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
const int N=666,mod=998244353;
int k,a,h,rk[N],srk[N],g[N];
vector<pair<int,int>>l1,l2,r1,r2;
void sol(int l,int r,vector<pair<int,int>>&s1,vector<pair<int,int>>&s2)
{
	int len=r-l+1;
	int tot=0;
	while(len)
	{
		len/=2;
		tot+=len;
	}
	int up=1<<tot;
	for(int i=0;i<up;i++)
	{
		int cur=k+1;
		vector<int>vc;
		rep(j,l,r) vc.push_back(j);
		int s=0;
		int mul=0;
		while(vc.size()>1)
		{
			vector<int>gc;
			for(int j=0;j<vc.size();j+=2)
			{
				if(i>>s&1)
					mul=(mul+1ll*vc[j]*g[cur])%mod,gc.push_back(vc[j+1]);
				else mul=(mul+1ll*vc[j+1]*g[cur])%mod,gc.push_back(vc[j]);
				s++;
			}
			vc=gc;
			cur--;
		}
		assert(s==tot);
		assert(cur==2);
		assert(vc.size()==1);
		s1.push_back({(mul+1ll*vc[0]*g[1])%mod,i});
		s2.push_back({(mul+1ll*vc[0]*g[2])%mod,i});
	}
}
int ans[N];
int cal(int i,int l,int r)
{
	vector<int>vc;
	rep(j,l,r) vc.push_back(j);
	int s=0,cur=k+1;
	while(vc.size()>1)
	{
		vector<int>gc;
		for(int j=0;j<vc.size();j+=2)
		{
			if(i>>s&1)
				ans[vc[j]]=rk[cur],gc.push_back(vc[j+1]);
			else ans[vc[j+1]]=rk[cur],gc.push_back(vc[j]);
			s++;
		}
		vc=gc;
		cur--;
	}
	return vc[0];
}
void get(vector<pair<int,int>>&l,vector<pair<int,int>>&r,int rkl,int rkr)
{
	sort(r.begin(),r.end());
	for(pair<int,int>x:l)
	{
		int pos=lower_bound(r.begin(),r.end(),make_pair((h+mod-x.first)%mod,0))-r.begin();
		if(pos>=0&&pos<r.size()&&r[pos].first==(h+mod-x.first)%mod)
		{
			int a=cal(x.second,1,1<<(k-1)),b=cal(r[pos].second,(1<<(k-1))+1,1<<k);
			ans[a]=rkl;ans[b]=rkr;
			for(int i=1;i<=(1<<k);i++)
				printf(i==(1<<k)?"%d\n":"%d ",ans[i]);
			exit(0);
		}
	}
}
void sol(int cas)
{
	sc(k,a,h);
	for(int i=1;i<=k+1;i++)
		rk[i]=i-2>=0?(1<<(i-2))+1:1;
	for(int i=1;i<=k+1;i++)
	{
		g[i]=1;
		rep(j,1,rk[i]) g[i]=1ll*g[i]*a%mod;
	}
	sol(1,1<<(k-1),l1,l2);
	sol((1<<(k-1))+1,1<<k,r1,r2);
	get(l1,r2,1,2);
	get(l2,r1,2,1);
	out(-1);
}
int main()
{
//   freopen("1.in", "r",stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
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