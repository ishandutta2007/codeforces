#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

struct node{int from,to,cap,flow;};
vector <node> edges;
vector <int> mp[maxn];
int n,m,s,t,d[maxn],cur[maxn];
bool vis[maxn];
queue <int> que;

inline void add_edge(int u,int v,int w)
{
	edges.push_back((node){u,v,w,0});
	edges.push_back((node){v,u,0,0});
	int pp=edges.size();
	mp[u].push_back(pp-2);
	mp[v].push_back(pp-1);
}

inline bool bfs()
{
	for(int i=0;i<=t;i++) d[i]=inf,vis[i]=0; d[s]=0; vis[s]=1; que.push(s);
	while(!que.empty())
	{
		int u=que.front(); que.pop();
		for(int i=0;i<mp[u].size();i++)
		{
			node v=edges[mp[u][i]];
			if(v.cap-v.flow>0&&!vis[v.to])
			{
				d[v.to]=d[u]+1;
				vis[v.to]=1; que.push(v.to);
			}
		}
	}
	if(vis[t]) return true;
	return false;
}

inline int dfs(int u,int w)
{
	int flow=0,r=0;
	if(u==t||w==0) return w;
	for(int i=0;i<mp[u].size();i++)
	{
		node &v=edges[mp[u][i]];
		if(d[v.to]==d[u]+1&&(r=dfs(v.to,min(v.cap-v.flow,w)))>0)
		{
			flow+=r;
			edges[mp[u][i]].flow+=r;
			edges[mp[u][i]^1].flow-=r;
			w-=r;
			if(w==0) break;
		}
	}
	return flow;
}

inline int max_flow()
{
	int ff=0;
	while(bfs())
	{
		memset(cur,0,sizeof(cur));
		ff+=dfs(s,inf);
	}
	return ff;
}

struct node2{int p,c,l;}w[maxn],w2[maxn];
bool pri[maxn];
int prime[maxn],cnt,k,ans;

inline bool cmp(node2 a,node2 b){return a.l<b.l;}

inline bool cmp2(node2 a,node2 b)
{
	if(a.c!=b.c) return a.c<b.c;
	return a.p<b.p;
}

inline void clear()
{
	edges.clear();
	for(int i=0;i<=t;i++) mp[i].clear();
}

inline bool jud(int x)
{
	clear();
	int fl=0,tmp=0; 
	for(int i=1;i<=n;i++) if(w[i].l>x) {fl=i-1; break;}
	if(fl==0) fl=n;
	for(int i=1;i<=fl;i++) tmp+=w[i].p;
	for(int i=1;i<=fl;i++)
	{
		if(w[i].c%2==0) add_edge(s,i,w[i].p);
		else add_edge(i,t,w[i].p);
	}
	for(int i=1;i<=fl;i++)
	{
		if(w[i].c%2==0)
			for(int j=1;j<=fl;j++)
				if(w[j].c%2==1&&pri[w[i].c+w[j].c]==0)
					add_edge(i,j,inf);
	}
	if(tmp-max_flow()>=k) return true;
	return false;
}

int main()
{
	n=read(); k=read(); s=0; t=n+1;
	for(int i=1;i<=n;i++) w[i].p=read(),w[i].c=read(),w[i].l=read();
	for(int i=2;i<=maxn-4;i++)
	{
		if(pri[i]==0) prime[++cnt]=i;
		for(int j=1;i*prime[j]<=maxn-4&&j<=cnt;j++)
		{
			pri[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	sort(w+1,w+n+1,cmp2);
	if(w[1].c==1)
	{
		int fl=n,cnt3=0;
		for(int i=1;i<=n;i++) if(w[i].c!=1) {fl=i-1; break;}
		for(int i=fl;i<=n;i++) w2[++cnt3]=w[i];
		memset(w,0,sizeof(w));
		for(int i=1;i<=cnt3;i++) w[i]=w2[i]; n=cnt3;
	}
	sort(w+1,w+n+1,cmp);
	int l=w[1].l,r=w[n].l;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(jud(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(ans==0) puts("-1");
	else cout<<ans<<endl;
	return 0;
}