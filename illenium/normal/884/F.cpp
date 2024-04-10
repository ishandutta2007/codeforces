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
#define maxn 2005
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
int n,m,s,t,d[maxn],p[maxn],flow,cost,a[maxn],val[maxn],sum;
vector <int> mp[maxn];
vector <edge> edges;
queue <int> que;
bool inq[maxn],fix[maxn];

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

string str;

int main()
{
	n=read(); s=0,t=2*n+1;
	cin>>str; str=" "+str;
	for(int i=1;i<=n;i++) val[i]=read(),sum+=val[i];
	for(int i=1;i<=n/2;i++)
		if(val[i]>val[n-i+1])  fix[i]=1,add_edge(i,n+i,1,0);
		else fix[n-i+1]=1,add_edge(n-i+1,2*n+1-i,1,0);
	for(int i=1;i<=n;i++) add_edge(s,i,1,0),add_edge(n+i,t,1,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(fix[i]||fix[j]) continue;
			if(str[i]==str[n-j+1]||str[j]==str[n-i+1]) continue;
			if(i==j) add_edge(i,n+j,1,0);
			else add_edge(i,n+j,1,val[j]);
		}
	while(spfa()); cout<<sum-cost;
	return 0;
}