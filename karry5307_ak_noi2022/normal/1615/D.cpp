#include<cstdio>
#include<vector>

using namespace std;

int n,m;
vector<pair<int,int> > ed[500000];

#define ID(i,j)((i)+(j)*n)

struct BCJ
{
	int fa[500000];
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
	int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
	void conn(int x,int y){fa[fnd(x)]=fnd(y);}
}B;

int cntbit(int v)
{
	int ans=0;
	while(v)
	{
		ans^=v&1;
		v>>=1;
	}
	return ans;
}

void merge(int x,int y,int v)
{
	if(v==0)B.conn(ID(x,0),ID(y,0)),B.conn(ID(x,1),ID(y,1));else B.conn(ID(x,0),ID(y,1)),B.conn(ID(x,1),ID(y,0));
}

void dfs_solve(int u,int f)
{
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].first;if(v==f)continue;
		if(ed[u][i].second!=-1)printf("%d %d %d\n",u,v,ed[u][i].second);
		else printf("%d %d %d\n",u,v,B.fnd(ID(u,0))==B.fnd(ID(v,1)));
		dfs_solve(v,u);
	}
}

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);B.init(2*n);
		for(int i=1;i<=n;i++)ed[i].clear();
		for(int i=1,x=0,y=0,v=0;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&v);ed[x].push_back(make_pair(y,v)),ed[y].push_back(make_pair(x,v));
			if(v!=-1){merge(x,y,cntbit(v)&1);}
		}
		for(int i=1,x=0,y=0,v=0;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&v);merge(x,y,v);
		}
		bool fl=1;
		for(int i=1;i<=n;i++)if(B.fnd(ID(i,0))==B.fnd(ID(i,1))){fl=0;break;}
		if(!fl){puts("NO");continue;}
		for(int i=2;i<=n;i++)if(B.fnd(ID(i,0))!=B.fnd(ID(1,0))&&B.fnd(ID(i,0))!=B.fnd(ID(1,1)))merge(i,1,0);
		puts("YES");dfs_solve(1,0);
	}
}