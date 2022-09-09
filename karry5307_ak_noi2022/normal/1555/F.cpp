#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct BCJ
{
	int fa[1000000];
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
	int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
	void conn(int x,int y){fa[fnd(x)]=fnd(y);}
}B;

int u[1000000],v[1000000],x[1000000];
vector<pair<int,int> > ed[1000000];

bool ans[1000000];


int dep[400000],dis[400000],E[1000000],dfn[400000],fa[400000],sz[400000],rdf[400000];

void dfs_bas(int u,int f)
{
    E[++E[0]]=u;dfn[u]=E[0],fa[u]=f;dep[u]=dep[f]+1;
    sz[u]=1,rdf[u]=++rdf[0];
    for(int i=0;i<ed[u].size();i++)
    {
        int v=ed[u][i].first;
        if(v==f)continue;
        dis[v]=dis[u]^ed[u][i].second;dfs_bas(v,u);E[++E[0]]=u;sz[u]+=sz[v];
    }
}


struct ST
{
    int minn[800000][20],lg[800000];
    void build()
    {
        lg[0]=-1;
        for(int i=1;i<=E[0];i++)minn[i][0]=E[i],lg[i]=lg[i>>1]+1;
        for(int j=1;(1<<j)<=E[0];j++)
        {
            for(int i=1;i+(1<<j)-1<=E[0];i++)
            {    
                minn[i][j]=dep[minn[i][j-1]]<dep[minn[i+(1<<(j-1))][j-1]]?
                    minn[i][j-1]:minn[i+(1<<(j-1))][j-1];
            }
        }
    }
    int query(int l,int r){int len=lg[r-l+1];
        return dep[minn[l][len]]<dep[minn[r-(1<<len)+1][len]]?
            minn[l][len]:minn[r-(1<<len)+1][len];}
}L;

int LCA(int x,int y)
{
    if(dfn[x]>dfn[y])swap(x,y);return L.query(dfn[x],dfn[y]);
}

int lowbit(int x){return x&-x;}

struct BIT
{
	int n,c[400000];
	void init(int N){n=N;for(int i=1;i<=n;i++)c[i]=0;}
	int sum(int x){int ans=0;while(x){ans+=c[x];x-=lowbit(x);}return ans;}
	void add(int x,int v){while(x<=n){c[x]+=v;x+=lowbit(x);}}
}BT;

int main()
{
	int n=0,q=0;scanf("%d%d",&n,&q);B.init(n);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&x[i]);if(B.fnd(u[i])!=B.fnd(v[i])){B.conn(u[i],v[i]);ans[i]=1;
			ed[u[i]].push_back(make_pair(v[i],x[i])),ed[v[i]].push_back(make_pair(u[i],x[i]));}
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])dfs_bas(i,0);
	}
	//for(int i=1;i<=n;i++)printf("%d ",fa[i]);puts("");
	L.build();BT.init(n);//return 0;
	for(int i=1;i<=q;i++)
	{
		if(!ans[i])
		{
			if(x[i]^dis[u[i]]^dis[v[i]])
			{
				//printf("%d\n",i);
				int l=LCA(u[i],v[i]);//printf("%d\n",l);
				if(BT.sum(rdf[u[i]])+BT.sum(rdf[v[i]])-2*BT.sum(rdf[l])==0)
				{
					ans[i]=1;int p=u[i];
					while(p!=l){BT.add(rdf[p],1),BT.add(rdf[p]+sz[p],-1);p=fa[p];}
					p=v[i];
					while(p!=l){BT.add(rdf[p],1),BT.add(rdf[p]+sz[p],-1);p=fa[p];}
				}
			}
		}
	}
	for(int i=1;i<=q;i++)puts(ans[i]?"YES":"NO");
}