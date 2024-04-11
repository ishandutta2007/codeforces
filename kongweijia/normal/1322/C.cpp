#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)
#define infty 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
//head

const int maxn=500000;

VI e[maxn+5];
ll a[maxn+5];

void solve()
{
	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,n) e[i].clear();
	rep(i,1,n) scanf("%I64d",&a[i]);
	rep(i,1,m)
	{
		int x,y; scanf("%d%d",&x,&y);
		e[x].pb(y);
	}
	map<int,int> M;
	int tot=0;
	rep(i,1,n)
	{
		map<int,int> go;
		for(auto x: e[i])
		{
			if(go[M[x]]==0)
			{
				go[M[x]]=++tot;
			}
			M[x]=go[M[x]];
		}
	}
	map<int,ll> dp;
	rep(i,1,n) if(M[i]!=0) dp[M[i]]+=a[i];
	ll g=0;
	for(auto it: dp) g=__gcd(g,it.yy);
	printf("%I64d\n",g);
}

int main()
{
	int CAS; scanf("%d",&CAS);
	while(CAS--)
	{
		solve();
	}
	return 0;
}