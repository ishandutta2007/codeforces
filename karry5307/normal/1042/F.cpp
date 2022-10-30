#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51;
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
vector<ll>v[MAXN];
ll nc,kk,tot,from,to,res;
ll last[MAXN],deg[MAXN];
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
inline ll dfs(ll node,ll fa)
{
	if(!(deg[node]-1))
	{
		return 0;
	}
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa)
		{
			v[node].push_back(dfs(ed[i].to,node)+1);
		}
	}
	sort(v[node].begin(),v[node].end());
	for(register int i=v[node].size()-1;i;i--)
	{
		if(v[node][i]+v[node][i-1]<=kk)
		{
			return v[node][i];
		}
		res++;
	}
	return v[node][0];
}
int main()
{
	nc=read(),kk=read();
	for(register int i=0;i<nc-1;i++)
	{
		deg[from=read()]++,deg[to=read()]++;
		addEdge(from,to),addEdge(to,from);
	}
	for(register int i=1;i<=nc;i++)
	{
		if((deg[i]-1))
		{
			dfs(i,0);
			break;
		}
	}
	printf("%d\n",res+1);
}