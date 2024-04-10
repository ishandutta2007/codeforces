#include<bits/stdc++.h>
using namespace std;
typedef int ll;
struct edge{
    ll to,prev;
};
edge ed[5000001];
ll tot,num,dist,top,cnt,nc;
ll last[5000001],dfn[5000001],low[5000001],ins[5000001],belong[5000001],size[5000001];
stack<ll>st;
inline void addEdge(ll from,ll to)
{
    ed[++tot].to=to;
    ed[tot].prev=last[from];
    last[from]=tot;
}
inline void tarjan(ll node)
{
    dfn[node]=low[node]=++num;
    st.push(node),ins[node]=1;
    ll flag=0,to;
    for(register int i=last[node];i;i=ed[i].prev)
    {
        to=ed[i].to;
        if(!dfn[to])
        {
            tarjan(to);
            low[node]=min(low[node],low[to]);
        }
        else
        {
            if(ins[to])
            {
                low[node]=min(low[node],dfn[to]);
            }
        }
    }
    if(dfn[node]==low[node])
    {
        cnt++;
        ll nd;
        do
        {
            nd=st.top(),st.pop();
            ins[nd]=0;
            belong[nd]=cnt;
            size[cnt]++;
        }
        while(node!=nd);
    }
}
int main()
{
    scanf("%d",&nc);
    for(register int i=0;i<nc;i++)
    {
    	for(register int j=0;j<nc;j++)
    	{
    		scanf("%d",&dist);
    		if(dist)
    		{
    			addEdge(i+1,j+1); 
			}
		}
	}
    for(register int i=1;i<=nc;i++)
    {
        if(!dfn[i])
        {
            tarjan(i);
        }
    }
    cnt==1?printf("YES\n"):printf("NO\n");
}