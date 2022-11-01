#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef long double db;
const ll MAXN=2e5+51;
struct Line{
	ll k,b;
	Line(ll k=-1e9,ll b=-1e18)
	{
		this->k=k,this->b=b;
	}
};
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
ll nc,tot,rt,sz,cur,res,from,to;
ll last[MAXN],val[MAXN],vis[MAXN];
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
inline db intersect(Line x,Line y)
{
	return 1.0*(y.b-x.b)/(x.k-y.k);
}
namespace SegmentTree{
	Line tree[MAXN<<2];
	inline void create(ll l,ll r,ll node)
	{
		if(tree[node].k!=-1e9||tree[node].b!=-1e18)
		{
			tree[node]=Line();
			ll mid=(l+r)>>1;
			if(l!=r)
			{
				create(l,mid,node<<1);
				create(mid+1,r,(node<<1)|1);
			}
		}
	}
	inline void insert(ll l,ll r,Line lx,ll node)
	{
		Line cur=tree[node];
		if(cur.k==lx.k)
		{
			tree[node]=cur.b>lx.b?cur:lx;
			return;
		}
		if(lx.k>cur.k)
		{
			swap(lx,cur);
		}
		ll mid=(l+r)>>1;
		db x=intersect(lx,cur);
		if(x<=l)
		{
			tree[node]=cur;
			return;
		}
		if(x>=r)
		{
			tree[node]=lx;
			return;
		}
		if(x<=mid)
		{
			tree[node]=cur;
			if(l!=r)
			{
				insert(l,mid,lx,node<<1);
			}
		}
		else
		{
			tree[node]=lx;
			if(l!=r)
			{
				insert(mid+1,r,cur,(node<<1)|1);
			}
		}
	}
	inline ll eval(Line l,ll x)
	{
		return l.k*x+l.b;
	}
	inline ll query(ll l,ll r,ll x,ll node)
	{
		if(l==r)
		{
			return eval(tree[node],x);
		}
		ll mid=(l+r)>>1,res;
		res=x<=mid?query(l,mid,x,node<<1):query(mid+1,r,x,(node<<1)|1);
		return max(eval(tree[node],x),res);
	}
}
using SegmentTree::create;
using SegmentTree::insert;
using SegmentTree::query;
inline void getSize(ll node)
{
	vis[node]=1,cur++;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(!vis[ed[i].to])
		{
			getSize(ed[i].to);
		}
	}
	vis[node]=0;
}
inline ll findCentroid(ll node)
{
	ll sz=1,maxn=1,szz;
	vis[node]=1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(!vis[ed[i].to])
		{
			szz=findCentroid(ed[i].to),maxn=max(maxn,szz),sz+=szz;
		}
	}
	maxn=max(maxn,cur-sz);
	if(maxn<::sz)
	{
		::sz=maxn,rt=node;
	}
	return vis[node]=0,sz;
}
inline void dfs(ll node,ll sum,ll sz,ll val)
{
	res=max(res,query(1,nc,sz,1)+sum),vis[node]=1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(!vis[ed[i].to])
		{
			dfs(ed[i].to,sum+::val[ed[i].to]+val,sz+1,::val[ed[i].to]+val);
		}
	}
	vis[node]=0;
}
inline void ddfs(ll node,ll sum,ll sz,ll val)
{
	insert(1,nc,Line(val,sum),1),vis[node]=1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(!vis[ed[i].to])
		{
			ddfs(ed[i].to,sum+(sz+1)*::val[ed[i].to],sz+1,::val[ed[i].to]+val);
		}
	}
	vis[node]=0;
}
inline void calc(ll node)
{
	vector<ll>nxt;
	sz=0x3f3f3f3f,cur=0,getSize(node),findCentroid(node),vis[node=rt]=1;
	create(1,nc,1),insert(1,nc,Line(0,0),1);
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(!vis[ed[i].to])
		{
			nxt.push_back(ed[i].to);
			dfs(ed[i].to,2*val[node]+val[ed[i].to],2,val[node]+val[ed[i].to]);
			ddfs(ed[i].to,val[ed[i].to],1,val[ed[i].to]);
		}
	}
	res=max(res,query(1,nc,1,1)+val[node]),create(1,nc,1),reverse(all(nxt));
	for(auto p:nxt)
	{
		dfs(p,2*val[node]+val[p],2,val[node]+val[p]);
		ddfs(p,val[p],1,val[p]);
	}
	for(auto p:nxt)
	{
		calc(p);
	}
}
int main()
{
	nc=read(),res=-1e18;
	for(register int i=0;i<nc-1;i++)
	{
		from=read(),to=read();
		addEdge(from,to),addEdge(to,from);
	}
	for(register int i=1;i<=nc;i++)
	{
		val[i]=read();
	}
	calc(1),printf("%lld\n",res);
}