#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e5+51;
struct Edge{
	ll to,prev,dist;
};
struct Node{
	ll to,dist;
	Node(ll to,ll dist)
	{
		this->to=to;
		this->dist=dist;
	}
};
Edge ed[MAXN<<1];
vector<Node>son[MAXN];
ll nc,from,to,dist,tot,res;
ll last[MAXN],size[MAXN],cost[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline void addEdge(ll from,ll to,ll dist)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	ed[tot].dist=dist;
	last[from]=tot;
}
inline ll cmp(Node x,Node y)
{
	return cost[x.to]*1.0/size[x.to]<cost[y.to]*1.0/size[y.to]; 
}
inline void dfs(ll node,ll f)
{
	size[node]=1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=f)
		{
			dfs(ed[i].to,node);
			size[node]+=size[ed[i].to];
			cost[ed[i].to]+=ed[i].dist,cost[node]+=cost[ed[i].to];
			son[node].push_back(Node(ed[i].to,ed[i].dist));
		}
	}
	sort(son[node].begin(),son[node].end(),cmp);
}
inline void ddfs(ll node)
{
	res+=dist;
	for(register int i=0;i<son[node].size();i++)
	{
		dist+=son[node][i].dist;
		ddfs(son[node][i].to);
		dist+=son[node][i].dist;
	}
}
int main()
{
	nc=read();
	for(register int i=0;i<nc-1;i++)
	{
		from=read(),to=read(),dist=read();
		addEdge(from,to,dist),addEdge(to,from,dist);
	}
	dfs(1,0),dist=0,ddfs(1);
	printf("%.8lf",res*1.0/(nc-1));
}