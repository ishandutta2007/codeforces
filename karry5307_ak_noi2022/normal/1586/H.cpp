#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int val[300000];

vector<pair<int,int> > ed[300000];

int fa[300000][20],maxt[300000][20],dfn[300000],dep[300000];

void dfs_bas(int u,int f)
{
	dep[u]=dep[f]+1,dfn[u]=++dfn[0];fa[u][0]=f;for(int i=1;i<20;i++)fa[u][i]=fa[fa[u][i-1]][i-1],maxt[u][i]=max(maxt[u][i-1],maxt[fa[u][i-1]][i-1]);
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].first;if(v==f)continue;
		maxt[v][0]=ed[u][i].second;dfs_bas(v,u);
	}
}

int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);for(int i=19;i>=0;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];if(x==y)return x;
	for(int i=19;i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];return fa[x][0];
}
int query_anc(int x,int d)
{
	int ans=0;for(int i=19;i>=0;i--)if(d&(1<<i)){ans=max(ans,maxt[x][i]);x=fa[x][i];}return ans;
}
int query_path(int x,int y)
{
	int l=LCA(x,y);return max(query_anc(x,dep[x]-dep[l]),query_anc(y,dep[y]-dep[l]));
}

struct Tree
{
	int n;
	vector<int> ed[500000];int val[500000],calc[500000],arg[500000];
	int fa[500000][20],dep[500000],dfn[500000],sz[500000],ev[500000];
	void dfs_bas(int u,int f)
	{
		fa[u][0]=f,dfn[u]=++dfn[0],sz[u]=1,dep[u]=dep[f]+1;
		for(int i=1;i<20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
		
		for(int i=0;i<ed[u].size();i++){int v=ed[u][i];if(v==f)continue;dfs_bas(v,u);sz[u]+=sz[v];}
	}
	int LCA(int x,int y)
	{
		if(dep[x]<dep[y])swap(x,y);for(int i=19;i>=0;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];if(x==y)return x;
		for(int i=19;i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];return fa[x][0];
	}
}Y;

struct BCJ
{
	int fa[500000];
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
	int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
	void conn(int x,int y){fa[fnd(x)]=fnd(y);}
}B;

struct e
{
	int a,b,c,t;
}ined[300000];
bool ccmp(e A,e B){return A.c<B.c;}
bool tcmp(e A,e B){return A.t<B.t;}
bool ydfncmp(int x,int y){return Y.dfn[x]<Y.dfn[y];}

int main()
{
	int n=0,q=0;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=1;i<n;i++)scanf("%d%d%d%d",&ined[i].a,&ined[i].b,&ined[i].c,&ined[i].t),
		ed[ined[i].a].push_back(make_pair(ined[i].b,ined[i].t)),ed[ined[i].b].push_back(make_pair(ined[i].a,ined[i].t));
	
	dfs_bas(1,0);
	int c=n;B.init(2*n-1);sort(ined+1,ined+n,ccmp);
	for(int i=1;i<=n;i++)Y.val[i]=val[i],Y.arg[i]=i;
	for(int i=n-1;i>=1;i--)
	{
		if(B.fnd(ined[i].a)!=B.fnd(ined[i].b))
		{
			int u=B.fnd(ined[i].a),v=B.fnd(ined[i].b);
			c++;Y.ed[c].push_back(u),Y.ed[c].push_back(v);B.conn(u,c),B.conn(v,c);
			Y.val[c]=max(Y.val[u],Y.val[v]);//printf("%d %d %d\n",u,v,c);
			Y.ev[c]=ined[i].c;
			if(Y.val[c]!=Y.val[u]){Y.calc[c]=Y.calc[v],Y.arg[c]=Y.arg[v];}
			else if(Y.val[c]!=Y.val[v]){Y.calc[c]=Y.calc[u],Y.arg[c]=Y.arg[u];}
			else
			{
				Y.calc[c]=max(max(Y.calc[u],Y.calc[v]),query_path(Y.arg[u],Y.arg[v]));
				Y.arg[c]=Y.arg[u];
			}
		}
	}
	Y.dfs_bas(2*n-1,0);
	//for(int i=1;i<=2*n-1;i++)printf("%d ",Y.arg[i]);puts("");
	
	while(q--)
	{
		int x=0,v=0;scanf("%d%d",&v,&x);
		int u=x;for(int i=19;i>=0;i--)if(Y.fa[u][i]&&Y.ev[Y.fa[u][i]]>=v)u=Y.fa[u][i];
		//printf("%d\n",u);
		printf("%d %d\n",Y.val[u],max(Y.calc[u],query_path(x,Y.arg[u]))/*,Y.arg[u],query_path(x,Y.arg[u])*/);
	}
}