#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e5+51;
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
ll nc,ec,tot,qcnt,from,to,l,r,mid,ql,qr,res,top;
li ress;
ll last[MAXN],vis[MAXN],loop[MAXN],st[MAXN],x[MAXN];
li prefix[MAXN];
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
inline void dfs(ll node,ll fa)
{
	ll maxn,minn,p;
	vis[node]=1,st[++top]=node;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa&&!loop[ed[i].to])
		{
			if(!vis[ed[i].to])
			{
				dfs(ed[i].to,node);
			}
			else
			{
				maxn=0,minn=nc+1;
				for(register int j=top;;j--)
				{
					maxn=max(maxn,(p=st[j])),minn=min(minn,p);
					loop[p]=1;
					if(st[j]==ed[i].to)
					{
						break;
					}
				}
				x[maxn]=max(x[maxn],minn);
			}
		}
	}
	top--;
}
inline void solve()
{
	l=ql=read(),r=qr=read(),res=r+1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		x[mid]>=ql?r=mid-1,res=mid:l=mid+1;
	}
	ress=(li)(ql+qr)*(qr-ql+1)/2-(prefix[qr]-prefix[res-1]);
	ress-=(li)(ql-1)*(res-ql);
	printf("%lld\n",ress);
}
int main()
{
	nc=read(),ec=read();
	for(register int i=0;i<ec;i++)
	{
		from=read(),to=read();
		addEdge(from,to),addEdge(to,from);
	}
	for(register int i=1;i<=nc;i++)
	{
		if(!vis[i])
		{
			dfs(i,0);
		}
	}
	qcnt=read();
	for(register int i=1;i<=nc;i++)
	{
		prefix[i]=prefix[i-1]+(x[i]=max(x[i],x[i-1]));
	}
	for(register int i=0;i<qcnt;i++)
	{
		solve();
	}
}