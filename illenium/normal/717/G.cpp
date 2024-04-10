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
#define ull unsigned long long
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
struct edge{int from,to,cap,flow,cost;};
int n,m,s,t,d[maxn],p[maxn],flow,cost,a[maxn];
vector <int> mp[maxn];
vector <edge> edges;
queue <int> que;
bool inq[maxn];

inline void add_edge(int u,int v,int w,int c)
{
	edges.push_back((edge){u,v,w,0,c});
	edges.push_back((edge){v,u,0,0,-c});
	int pp=edges.size();
	mp[u].push_back(pp-2);
	mp[v].push_back(pp-1);
}

inline bool spfa()
{
	for(int i=s;i<=t;i++) d[i]=inf,a[i]=inf,inq[i]=0;
	que.push(s); d[s]=0; inq[s]=1;
	while(!que.empty())
	{
		int u=que.front(); que.pop(); inq[u]=0;
		for(int i=0;i<mp[u].size();i++)
		{
			edge v=edges[mp[u][i]];
			if(v.cap-v.flow>0&&d[v.to]>d[u]+v.cost)
			{
				a[v.to]=min(a[u],v.cap-v.flow);
				p[v.to]=mp[u][i];
				d[v.to]=d[u]+v.cost;
				if(!inq[v.to]) que.push(v.to),inq[v.to]=1;
			}
		}
	}
	if(d[t]==inf) return false;
	flow+=a[t];
	cost+=d[t]*a[t];
	for(int i=t;i!=s;i=edges[p[i]].from)
	{
		edges[p[i]].flow+=a[t];
		edges[p[i]^1].flow-=a[t];
	}
	return true;
}

ull h[maxn],pre[maxn];
char ch[maxn],ss[maxn];

inline ull gethash(int l,int r)
{
	return h[r]-h[l-1]*pre[r-l+1];
}

int main()
{
	n=read(); scanf("%s",ch+1); s=0,t=n+1; pre[0]=1;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]*233;
	for(int i=1;i<=n;i++) h[i]=h[i-1]*233+ch[i];
	m=read();
	while(m--)
	{
		ull p=0; scanf("%s",ss+1); int w=read(),len=strlen(ss+1);
		for(int i=1;i<=len;i++) p=p*233+ss[i];
		for(int i=1;i<=n-len+1;i++) if(p==gethash(i,i+len-1)) add_edge(i,i+len,1,-w);
	}
	int x=read();
	for(int i=1;i<n;i++) add_edge(i,i+1,x,0); add_edge(s,1,x,0); add_edge(n,t,x,0);
	while(spfa()); cout<<-cost<<endl;
	return 0;
}