#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
ll n,m,kk,tot,cur,nxt,fx,fy,totx,l,r,pu,pv,pp;
ll u[MAXN],v[MAXN],ffa[MAXN],fa[MAXN],indSet[MAXN],rp[MAXN];
ll tag[MAXN],last[MAXN],depth[MAXN],cx[2];
vector<ll>res;
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
inline ll find(ll x)
{
	return x==ffa[x]?x:ffa[x]=find(ffa[x]);
}
inline void addEdge(ll from,ll to)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	last[from]=tot;
}
inline void dfs(ll node,ll f)
{
	fa[node]=f,cx[depth[node]=depth[f]^1]++;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		ed[i].to!=f?dfs(ed[i].to,node):(void)(1);
	}
}
int main()
{
	n=read(),m=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		ffa[i]=i;
	}
	for(register int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read();
		if((fx=find(u[i]))!=(fy=find(v[i])))
		{
			addEdge(u[i],v[i]),addEdge(v[i],u[i]),ffa[fy]=fx,tag[i]=1;
		}
		else
		{
			if(totx)
			{
				continue;
			}
			tag[i]=1;
			dfs(u[i],0),indSet[++totx]=cur=v[i];
			for(;cur!=u[i];indSet[++totx]=cur=fa[cur]);
		}
	}
	if(!totx)
	{
		dfs(1,0),pp=cx[0]>cx[1]?0:1;
		for(register int i=1;i<=n;i++)
		{
			depth[i]==pp?res.push_back(i):(void)(1);
		}
		puts("1");
		for(register int i=0;i<(kk+1)>>1;i++)
		{
			printf("%d ",res[i]);
		}
		return 0;
	}
	for(register int i=1;i<=totx;i++)
	{
		rp[indSet[i]]=i;
	}
	l=1,r=totx;
	for(register int i=1;i<=m;i++)
	{
		if(!tag[i])
		{
			pu=rp[u[i]],pv=rp[v[i]],pu>pv?swap(pu,pv):(void)(1);
			if(l<=pu&&pu<=r&&l<=pv&&pv<=r)
			{
				l=pu,r=pv;
			}
		}
	}
	for(register int i=l;i<=r;i++)
	{
		res.push_back(indSet[i]);
	}
	if(r-l+1<=kk)
	{
		printf("2\n%d\n",r-l+1);
		for(register int i=0;i<r-l+1;i++)
		{
			printf("%d ",res[i]);
		}
	}
	else
	{
		puts("1");
		for(register int i=0,j=0;j<(kk+1)>>1;i+=2,j++)
		{
			printf("%d ",res[i]);
		}
	}
}