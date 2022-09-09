#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct line
{
	long long k,b;line(long long _k=0,long long _b=0):k(_k),b(_b){}
	long long operator()(long long x){return k*x+b;}
};
line operator+(line A,line B){return line(A.k+B.k,A.b+B.b);}
bool operator<(line A,line B){return A.k==B.k?A.b<B.b:A.k<B.k;}

bool is_ctr[200000],vis[200000];
vector<pair<int,line> > ed[200000];
int fa[200000],sz[200000],maxsz[200000];line L[200000];
int dfn[200000],rev[200000];

void dfs_bas(int u,int f)
{
	dfn[u]=++dfn[0],rev[dfn[u]]=u;
	fa[u]=f,sz[u]=1,maxsz[u]=0;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].first;if(!is_ctr[v]&&v!=f){L[v]=L[u]+ed[u][i].second;dfs_bas(v,u);sz[u]+=sz[v],maxsz[u]=max(maxsz[u],sz[v]);}
	}
}

struct SegmentTree
{
	struct nd
	{
		line L;int lc,rc,l,r;
	}t[2000000];int used,n,pos[2000000];
	int new_node(int l,int r)
	{
		++used;t[used].lc=t[used].rc=0,t[used].l=l,t[used].r=r,t[used].L.k=0,t[used].L.b=-1;return used;
	}
	void init(vector<int> P)
	{
		used=0;n=P.size();for(int i=0;i<n;i++)pos[i]=P[i];
		new_node(0,n-1);
	}
	void ins(line L,int k=1)
	{
		long long nl=L(pos[t[k].l]),nr=L(pos[t[k].r]),fl=t[k].L(pos[t[k].l]),fr=t[k].L(pos[t[k].r]);
		if(nl<=fl&&nr<=fr)return;
		if(nl>=fl&&nr>=fr){t[k].L=L;return;}
		int mid=(t[k].l+t[k].r)>>1;if(L(pos[mid])>t[k].L(pos[mid])){swap(L,t[k].L),swap(nl,fl),swap(nr,fr);}
		if(nl>fl){if(!t[k].lc)t[k].lc=new_node(t[k].l,mid);ins(L,t[k].lc);}
		else{if(!t[k].rc)t[k].rc=new_node(mid+1,t[k].r);ins(L,t[k].rc);}
	}
	line query_L(int p)
	{
		//printf("QUERY: %d\n",p);
		line L(0,-1);long long ans=-1;int k=1;
		while(k)
		{
			if(t[k].L(p)>ans)L=t[k].L,ans=t[k].L(p);
			if(t[k].l==t[k].r)break;
			int mid=(t[k].l+t[k].r)>>1;k=p<=pos[mid]?t[k].lc:t[k].rc;
		}
		return L;
	}
	long long query_ans(int p)
	{
		long long ans=-1;int k=1;
		while(k)
		{
			if(t[k].L(p)>ans)ans=t[k].L(p);
			if(t[k].l==t[k].r)break;
			int mid=(t[k].l+t[k].r)>>1;k=p<=pos[mid]?t[k].lc:t[k].rc;
		}
		return ans;
	}
}T;

map<line,int> mp;
vector<int> task[200000];

long long ans[2000000];

int main()
{
	int n=0,m=0;scanf("%d%d",&n,&m);
	for(int i=1,u=0,v=0,a=0,b=0;i<n;i++)
	{
		scanf("%d%d%d%d",&u,&v,&a,&b);ed[u].push_back(make_pair(v,line(a,b))),ed[v].push_back(make_pair(u,line(a,b)));
	}
	dfs_bas(1,0);//for(int i=1;i<=n;i++)printf("%lld %lld\n",L[i].k,L[i].b);puts("");
	vector<int> X;for(int i=0;i<m;i++)X.push_back(i);T.init(X);
	for(int i=1;i<=n;i++)mp[L[i]]=i,T.ins(L[i]);
	for(int i=0;i<m;i++)
	{
		line L=T.query_L(i);//printf("%lld %lld\n",L.k,L.b);
		task[mp[L]].push_back(i);//printf("%d\n",mp[L]);
	}
	while(1)
	{
		bool quit=1;for(int i=1;i<=n;i++)if(!is_ctr[i])quit=0;if(quit)break;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(!is_ctr[i]&&!vis[i])
			{
				dfn[0]=0;dfs_bas(i,0);int c=sz[i];
				bool no_query=1;for(int j=1;j<=c;j++){if(task[rev[j]].size()){no_query=0;break;}}
				if(no_query){for(int j=1;j<=c;j++)is_ctr[rev[j]]=1;continue;}
				
				int r=0;
				for(int j=1;j<=c;j++){int u=rev[j];if(2*max(maxsz[u],c-sz[u])<=c){r=u;break;}}
				dfn[0]=0,L[r]=line(0,0);dfs_bas(r,0);
				X.clear();
				for(int j=1;j<=c;j++)
				{
					int u=rev[j];for(int x=0;x<task[u].size();x++)X.push_back(task[u][x]);
				}
				sort(X.begin(),X.end());T.init(X);
				T.ins(line(0,0));
				for(int j=0;j<ed[r].size();j++)
				{
					int p=ed[r][j].first;if(is_ctr[p])continue;
					for(int x=dfn[p];x<dfn[p]+sz[p];x++)
					{
						int k=rev[x];
						for(int y=0;y<task[k].size();y++)
						{
							int f=task[k][y];ans[f]=max(ans[f],L[k](f)+T.query_ans(f));
						}
					}
					for(int x=dfn[p];x<dfn[p]+sz[p];x++)
					{
						int k=rev[x];if(ed[k].size()<=1)T.ins(L[k]);
					}
				}
				for(int j=0;j<task[r].size();j++)
				{
					int f=task[r][j];ans[f]=max(ans[f],T.query_ans(f));
				}
				T.init(X);
				for(int j=ed[r].size()-1;j>=0;j--)
				{
					int p=ed[r][j].first;if(is_ctr[p])continue;
					for(int x=dfn[p];x<dfn[p]+sz[p];x++)
					{
						int k=rev[x];
						for(int y=0;y<task[k].size();y++)
						{
							int f=task[k][y];ans[f]=max(ans[f],L[k](f)+max(0ll,T.query_ans(f)));
						}
					}
					for(int x=dfn[p];x<dfn[p]+sz[p];x++)
					{
						int k=rev[x];if(ed[k].size()<=1)T.ins(L[k]);
					}
				}
				is_ctr[r]=1;for(int j=1;j<=c;j++)vis[rev[j]]=1;
			}
		}
	}
	for(int i=0;i<m;i++)printf("%lld ",ans[i]);
}