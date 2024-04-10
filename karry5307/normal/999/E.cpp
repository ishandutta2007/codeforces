#include<bits/stdc++.h>
using namespace std;
typedef int ll;
struct edge{
    ll to,prev;
};
edge ed[500001],scc[500001];
ll test,tot,num,top,cnt,nc,ec,capital,ans;
ll last[500001],sccLast[500001],dfn[500001],low[500001],ins[500001],belong[500001];
ll from[500001],to[500001],size[500001],in[500001];
stack<ll>st;
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
inline void addEdge(ll from,ll to)
{
    ed[++tot].to=to;
    ed[tot].prev=last[from];
    last[from]=tot;
}
inline void addSCC(ll from,ll to)
{
    scc[++tot].to=to;
    scc[tot].prev=sccLast[from];
    sccLast[from]=tot;
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
inline void mergePoint()
{
    tot=0;
    for(register int i=0;i<ec;i++)
    {
        if(belong[from[i]]!=belong[to[i]])
        {
            addSCC(belong[from[i]],belong[to[i]]);
            in[belong[to[i]]]++;
        }
    }
}
int main()
{
    nc=read(),ec=read(),capital=read();
    for(register int i=0;i<ec;i++)
    {
        from[i]=read(),to[i]=read();
        addEdge(from[i],to[i]);
    }
    for(register int i=1;i<=nc;i++)
    {
        if(!dfn[i])
        {
            tarjan(i);
        }
    }
    mergePoint();
    for(register int i=1;i<=cnt;i++)
    {
    	if(!in[i])
    	{
    		ans++;
        }
    }
    if(!in[belong[capital]])
    {
    	ans--;
	}
    cout<<ans<<endl;
}