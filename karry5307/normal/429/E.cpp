#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=4e5+51;
struct Edge{
	ll to,prev,id;
};
struct Item{
	ll l,r;
};
Edge ed[MAXN<<1];
Item it[MAXN];
ll n,tot=1,totd,lst;
ll last[MAXN],vis[MAXN],vis2[MAXN],deg[MAXN],res[MAXN],dsc[MAXN];
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
inline void addEdge(ll from,ll to,ll id)
{
	ed[++tot]={to,last[from],id},last[from]=tot;	
} 
inline void dfs(ll node)
{
	vis[node]=1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(!vis2[i])
		{
			vis2[i]=vis2[i^1]=1;
			res[ed[i].id]=(node<ed[i].to),dfs(ed[i].to);
		}
	}
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		dsc[++totd]=it[i].l=read(),dsc[++totd]=it[i].r=read()+1;
	}
	sort(dsc+1,dsc+totd+1),totd=unique(dsc+1,dsc+totd+1)-dsc-1;
	for(register int i=1;i<=n;i++)
	{
		it[i].l=lower_bound(dsc+1,dsc+totd+1,it[i].l)-dsc;
		it[i].r=lower_bound(dsc+1,dsc+totd+1,it[i].r)-dsc;
		addEdge(it[i].l,it[i].r,i),addEdge(it[i].r,it[i].l,i);
		deg[it[i].l]++,deg[it[i].r]++;
	}
	for(register int i=1;i<=totd;i++)
	{
		if(deg[i]&1)
		{
			lst?addEdge(i,lst,0),addEdge(lst,i,0),lst=0:lst=i;
		}
	}
	for(register int i=1;i<=totd;i++)
	{
		!vis[i]?dfs(i):(void)1;
	}
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",res[i]);
	}
}