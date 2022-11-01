#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,m;
int X[200005],Y[200005],ans[200005],res[200005];
int ord[200005];
int vis[200005],deg[200005];
vector<int> v[200005];

int col[200005];

struct dsu
{
	int fa[200005];
	int fnd(int x){return fa[x]==x?x:(fa[x]=fnd(fa[x]));}
	void init(){rep(i,n) fa[i]=i;}
	bool merge(int x,int y)
	{
		x=fnd(x);y=fnd(y);if(x==y)return 0;
		fa[x]=y;return 1;
	}
}d1,d2;

int rnd(){return (1ll*32768*rand()+rand())%1000000000;}

void solve()
{
	scanf("%d%d",&n,&m);
	rep(i,m)
	{
		scanf("%d%d",&X[i],&Y[i]);
		ans[i]=0;
		v[X[i]].push_back(i);
		v[Y[i]].push_back(i);
		deg[X[i]]++;deg[Y[i]]++;
	}
	int mn=m+1,_;
	for(;;)
	{
		rep(i,m) ord[i]=i;
		rep(i,m) swap(ord[i],ord[rnd()%i+1]);
		d1.init();d2.init();
		int cnt=0;
		rep(i,m)
		{
			int j=ord[i];
			if(!d1.merge(X[j],Y[j]))
			{
				ans[j]=0;
				if(!d2.merge(X[j],Y[j])) cnt++;
			}
			else
			{
				ans[j]=1;
			}
		}
		if(cnt<mn)
		{
			mn=cnt;
			rep(j,m) res[j]=ans[j];
		}
		if(mn==0) break;
	}
	rep(j,m) printf("%d",res[j]);
	puts("");return;
}

int main()
{
	srand(time(NULL));
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}