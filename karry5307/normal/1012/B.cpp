#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=4e5+51;
struct Edge{
    ll to,prev;
};
Edge ed[MAXN<<1];
ll lnc,rnc,ec,tmp,ccCnt,tot,from,to;
ll last[MAXN],belong[MAXN];
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
    ed[++tot].prev=last[from];
    ed[tot].to=to;
    last[from]=tot;
}
inline void dfs(ll node)
{
    for(register int i=last[node];i;i=ed[i].prev)
    {
        if(!belong[ed[i].to])
        {
            belong[ed[i].to]=ccCnt,dfs(ed[i].to);
        }
    }
}
int main()
{
    lnc=read(),rnc=read(),ec=read();
    for(register int i=0;i<ec;i++)
    {
        from=read(),to=read();
        addEdge(from,to+lnc),addEdge(to+lnc,from);
    }
    for(register int i=1;i<=lnc+rnc;i++)
    {
        if(!belong[i])
        {
            belong[i]=++ccCnt,dfs(i);
        }
    }
    printf("%d",ccCnt-1);
}