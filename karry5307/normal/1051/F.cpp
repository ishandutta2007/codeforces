#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e5+51;
struct Edge{
	ll to,prev,dist;
};
struct Tuple{
	ll x,y;
	inline bool operator <(const Tuple &rhs)const
	{
		return this->x>rhs.x;
	}
};
priority_queue<Tuple>pq;
set<ll>st;
set<ll>::iterator it;
Edge ed[MAXN<<1];
ll nc,ec,tot,from,to,d,ptr,qcnt,x,y,res;
ll last[MAXN],depth[MAXN],back[51],anc[MAXN][19],dist[MAXN][19];
ll dis[50][MAXN],inQueue[MAXN];
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
template <class T>
inline T Min(T x,T y)
{
	return x<y?x:y;
}
inline void addEdge(ll from,ll to,ll dist)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	ed[tot].dist=dist;
	last[from]=tot;
}
inline void dfs(ll node,ll fa,ll dis)
{
	anc[node][0]=fa,depth[node]=depth[fa]+1,dist[node][0]=dis;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa)
		{
			if(depth[ed[i].to])
			{
				st.insert(node),st.insert(ed[i].to);
				continue;
			}
			dfs(ed[i].to,node,ed[i].dist);
		}
	}
}
inline void LCASetup()
{
	for(register int j=1;j<=18;j++)
	{
		for(register int i=1;i<=nc;i++)
		{
			anc[i][j]=anc[anc[i][j-1]][j-1];
			dist[i][j]=dist[i][j-1]+dist[anc[i][j-1]][j-1];
		}
	}
}
inline ll LCA(ll x,ll y)
{
	ll res=0;
	if(depth[x]<depth[y])
	{
		swap(x,y);
	}
	for(register int i=18;i>=0;i--)
	{
		if(depth[anc[x][i]]>=depth[y])
		{
			res+=dist[x][i],x=anc[x][i];
		}
	}
	if(x==y)
	{
		return res;
	}
	for(register int i=18;i>=0;i--)
	{
		if(anc[x][i]!=anc[y][i])
		{
			res+=dist[x][i]+dist[y][i],x=anc[x][i],y=anc[y][i];
		}
	}
	return res+dist[x][0]+dist[y][0];
}
inline void Dijkstra(ll source,ll *dist)
{
	ll top;
	dist[source]=0,inQueue[source]=1,pq.push((Tuple){0,source});
	while(!pq.empty())
	{
		top=pq.top().y,pq.pop(),inQueue[top]=0;
		for(register int i=last[top];i;i=ed[i].prev)
		{
			if(dist[ed[i].to]>dist[top]+ed[i].dist)
			{
				dist[ed[i].to]=dist[top]+ed[i].dist;
				if(!inQueue[ed[i].to])
				{
					pq.push((Tuple){dist[ed[i].to],ed[i].to});
				}
			}
		}
	}	
}
int main()
{
	nc=read(),ec=read();
	for(register int i=0;i<ec;i++)
	{
		from=read(),to=read(),d=read();
		addEdge(from,to,d),addEdge(to,from,d); 
	}
	dfs(1,0,0),LCASetup(),memset(dis,0x3f,sizeof(dis)),qcnt=read();
	for(it=st.begin();it!=st.end();it++)
	{
		back[++ptr]=*it;
	}
	for(register int i=1;i<=ptr;i++)
	{
		Dijkstra(back[i],dis[i]);
	}
	for(register int i=0;i<qcnt;i++)
	{
		x=read(),y=read(),res=LCA(x,y);
		for(register int j=1;j<=ptr;j++)
		{
			res=Min(res,dis[j][x]+dis[j][y]);
		}
		printf("%lld\n",res);
	} 
}