#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pii;

#define mp make_pair
#define fi first
#define sc second
#define pb push_back

const int MAXM=100005,MAXK=45;

int pos[MAXM][MAXK],last[MAXM][MAXK],pre[MAXM][MAXK];
bool vis[MAXK];
vector <pii> fac[MAXK],v[MAXM];

void add(int x,int r,int l)
{
	v[x].pb(mp(r,l));
}

void solve(const vector <pii> &v)
{
	if (v.empty())
	{
		puts("0");
		return;
	}
	int ans=1;
	for (int i=0;i<v.size();)
	{
		int mx=v[i].fi,j;
		for (j=i+1;j<v.size()&&v[j].fi==v[j-1].fi+1;j++)
		{
			mx=max(mx,v[j].sc);
			ans=max(ans,v[j].fi-mx+1);
		}
		i=j;
	}
	printf("%d\n",ans);
}

int main()
{
	for (int i=2;i<=40;i++)
		if (!vis[i])
			for (int j=i;j<=40;j+=i)
			{
				vis[j]=true;
				int t=j;
				while (t%i==0)
					t/=i;
				fac[j].pb(mp(i,j/t));
			}
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for (int j=0;j<k;j++)
		{
			int x;
			scanf("%d",&x);
			int mx=1;
			for (int u=0;u<fac[k].size();u++)
			{
				int f=fac[k][u].fi,w=fac[k][u].sc,p=j%w;
				for (int v=f;v<=40;v*=f)
					if (p%v!=pos[x][v]%w)
						mx=max(mx,last[x][v]+1);
					else
						mx=max(mx,pre[x][v]+1);
				if (pos[x][w]!=p)
				{
					pos[x][w]=p;
					pre[x][w]=last[x][w];
				}
				last[x][w]=i;
			}
			add(x,i,mx);
		}
	}
	for (int i=1;i<=m;i++)
		solve(v[i]);
	return 0;
}