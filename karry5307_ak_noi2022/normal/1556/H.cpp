#pragma GCC optimize(2)

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n,k,a,b;
int d[300],c[300];

const int INF=1e9;

struct e
{
	int u,v,val;e(int _u=0,int _v=0,int _val=0):u(_u),v(_v),val(_val){}
};
bool operator<(e X,e Y){return X.val<Y.val;}

vector<e> A,B,C;

struct BCJ
{
	int fa[200];
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
	int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
	void conn(int u,int v){fa[fnd(u)]=fnd(v);}
}J;

bool in[5000];vector<int> ed[5000];

pair<int,int> P[5000];
queue<int> q;bool in_q[5000];pair<int,int> dis[5000];int pre[5000];

void spfa(int n,int s)
{
	for(int i=0;i<=n;i++)dis[i]=make_pair(INF,INF);dis[s]=make_pair(0,0);
	while(!q.empty())q.pop();q.push(s);
	memset(in_q,0,sizeof(in_q));
	while(!q.empty())
	{
		int u=q.front();q.pop();in_q[u]=0;
		for(int i=0;i<ed[u].size();i++)
		{
			int v=ed[u][i];
			pair<int,int> P=dis[u];P.second++;if(u<b){if(in[u])P.first-=B[u].val;else P.first+=B[u].val;}
			if(P<dis[v]){dis[v]=P,pre[v]=u;if(!in_q[v])in_q[v]=1,q.push(v);}
		}
	}
}

vector<int> G;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)scanf("%d",&d[i]);for(int i=k+1;i<=n;i++)d[i]=INF;
	for(int i=1,w=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			scanf("%d",&w);if(j<=k)A.push_back(e(i,j,w));else if(i<=k)B.push_back(e(i,j,w));else C.push_back(e(i,j,w));
		}
	}
	
	sort(C.begin(),C.end());J.init(n);
	for(int i=0;i<C.size();i++)
	{
		if(J.fnd(C[i].u)!=J.fnd(C[i].v))
		{
			B.push_back(C[i]);J.conn(C[i].u,C[i].v);
		}
	}
	a=A.size(),b=B.size();int ans=1e9;
	//for(int i=0;i<b;i++)printf("%d %d %d\n",B[i].u,B[i].v,B[i].val);
	for(int i=0;i<(1<<a);i++)
	{
		//printf("STA: %d\n",i);
		J.init(k);int cur=0,cnt=0;memset(c,0,sizeof(c));
		for(int j=0;j<a;j++)
			if(i&(1<<j))
			{
				//printf("%d %d\n",A[j].u,A[j].v);
				if(J.fnd(A[j].u)==J.fnd(A[j].v)){cur=-1;break;}J.conn(A[j].u,A[j].v);
				cnt++,cur+=A[j].val;c[A[j].u]++,c[A[j].v]++;
			}
		if(cur==-1)continue;
		for(int j=1;j<=k;j++)if(c[j]>d[j])cur=-1;if(cur==-1)continue;
		//printf("%d\n",cur);return 0;
		memset(in,0,sizeof(in));G.clear();
		while(cnt<n-1)
		{
			for(int j=0;j<=b+1;j++)ed[j].clear();
			for(int j=0;j<b;j++)
			{
				if(!in[j])
				{
					c[B[j].u]++,c[B[j].v]++;if(c[B[j].u]<=d[B[j].u]&&c[B[j].v]<=d[B[j].v])ed[j].push_back(b+1);c[B[j].u]--,c[B[j].v]--;
					
					J.init(n);for(int v=0;v<a;v++)if(i&(1<<v))J.conn(A[v].u,A[v].v);for(int u=0;u<b;u++)if(in[u])J.conn(B[u].u,B[u].v);
					if(J.fnd(B[j].u)!=J.fnd(B[j].v))ed[b].push_back(j);
				}
			}
			for(int U=0;U<G.size();U++)
			{
				int u=G[U];
				if(in[u])
				{
					J.init(n);for(int v=0;v<a;v++)if(i&(1<<v))J.conn(A[v].u,A[v].v);
					for(int V=0;V<G.size();V++){int v=G[V];if(in[v]&&v!=u)J.conn(B[v].u,B[v].v);}
					
					for(int j=0;j<b;j++)
					{
					if(in[j])continue;
					if(J.fnd(B[j].u)!=J.fnd(B[j].v))ed[u].push_back(j);
					
					c[B[u].u]--,c[B[u].v]--,c[B[j].u]++,c[B[j].v]++;
					if(c[B[j].u]<=d[B[j].u]&&c[B[j].v]<=d[B[j].v])ed[j].push_back(u);
					c[B[u].u]++,c[B[u].v]++,c[B[j].u]--,c[B[j].v]--;
					}
				}
			}
			/*puts("EDGES");
			for(int i=0;i<=b;i++)
			{
				printf("%d: ",i);for(int j=0;j<ed[i].size();j++)printf("%d ",ed[i][j]);puts("");
			}*/
			spfa(b+1,b);if(dis[b+1].first==INF)break;
			cur+=dis[b+1].first,cnt++;
			//printf("%d\n",cnt);
			int x=pre[b+1];
			while(x!=b)
			{
				if(in[x])c[B[x].u]--,c[B[x].v]--;else c[B[x].u]++,c[B[x].v]++;
				in[x]^=1;
				x=pre[x];
			}
			G.clear();for(int j=0;j<b;j++)if(in[j])G.push_back(j);
			//puts("POINTS");
			//for(int x=0;x<b;x++)if(in[x])printf("%d %d (%d)\n",B[x].u,B[x].v,x);
		}
		if(cnt==n-1)ans=min(ans,cur);
	}
	printf("%d",ans);
}