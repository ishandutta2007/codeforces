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
#define inf 0x3f3f3f3f
#define fi first
#define se second
const int N=105,mod=1e9+7;
int n,k;
vector<int>vc;
void sol(int cas)
{
	sc(n,k);
	priority_queue<int,vector<int>,greater<int>>q;
	int ones=n%10;
	n/=10;
	for(int i=2;i<=10;i++)
	{
		int t=n%10;
		while(t--) q.push(i);
		n/=10;
	}
	while(q.size()+ones<k)
	{
		int t=q.top();q.pop();
		t--;
		if(t==1) ones+=10;
		else
		{
			rep(i,1,10) q.push(t);
		}
	}
	vector<int>ans;
	while(ones--) ans.push_back(1);
	int cur=1,pre=1;
	while(!q.empty())
	{
		int x=q.top();q.pop();
		while(pre<x) cur*=10,pre++;
		ans.push_back(cur);
	}
	int res[100];memset(res,0,sizeof(res));
	int i=0;
	for(int x:ans)
	{
		res[i]+=x;
		i=(i+1)%k;
	}
	rep(i,0,k-1) printf(i==k-1?"%d\n":"%d ",res[i]);
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