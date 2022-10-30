//
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
struct edge{
    ll to,prev;  
};
ll nc,ec,query,root,from,to;
ll depth[500010],anc[500010][31],last[500010],diff[500010],prefix[500010],LCA,maxn;
ll From[500010],To[500010];
edge ed[500010*2];
inline void addEdge(ll from,ll to)
{
    ed[++ec].prev=last[from];
    ed[ec].to=to;
    last[from]=ec;
}
inline void dfs(ll node)
{
    ll son;
    for(register int i=last[node];i!=0;i=ed[i].prev)
    {
        son=ed[i].to;
        if(!depth[son])
        {
            depth[son]=depth[node]+1;
            anc[son][0]=node;
            dfs(son);
        }
    }
}
inline void LCASetup()
{
    depth[1]=1;
    anc[1][0]=0;
    dfs(1);
    for(register int i=1;i<=21;i++)
    {
        for(register int j=1;j<=nc;j++)
        {
            anc[j][i]=anc[anc[j][i-1]][i-1];
        }
    }
}
inline ll lca(ll x,ll y)
{
    if(depth[x]>depth[y])
    {
        swap(x,y);
    }
    for(register int i=21;i>=0;i--)
    {
        if(depth[anc[y][i]]>=depth[x])
        {
            y=anc[y][i];
        }
    }
    if(x==y)
    {
        return x;
    }
    for(register int i=21;i>=0;i--)
    {
        if(anc[x][i]!=anc[y][i])
        {
            x=anc[x][i];
            y=anc[y][i];
        }
    }
    return anc[x][0];
}
inline void ddfs(ll node)
{
    for(register int i=last[node];i;i=ed[i].prev)
    {
        if(ed[i].to==anc[node][0])
        {
            continue;
        }
        ddfs(ed[i].to);
        diff[node]+=diff[ed[i].to];
    }
}
inline void dffs(ll node,ll val)
{
	prefix[node]=diff[node]+val;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to==anc[node][0])
		{
			continue;
		}
		dffs(ed[i].to,prefix[node]);
	}
}
int main()
{
    scanf("%d",&nc);
    for(register int i=0;i<nc-1;i++)
    {
        scanf("%d%d",&from,&to);
        From[i]=from,To[i]=to;
        addEdge(from,to);
        addEdge(to,from);
    }
    LCASetup();
    scanf("%d",&query);
    for(register int i=0;i<query;i++)
    {
        scanf("%d%d",&from,&to);
        LCA=lca(from,to);
        diff[from]++,diff[to]++,diff[LCA]-=2;
    }
    ddfs(1);
    dffs(1,0);
    for(register int i=0;i<nc-1;i++)
    {
    	if(depth[From[i]]<depth[To[i]])
    	{
    		swap(From[i],To[i]);
		}
		printf("%d ",prefix[From[i]]-prefix[To[i]]);
	}
}