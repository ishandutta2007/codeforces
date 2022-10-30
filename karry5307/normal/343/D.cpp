#include<bits/stdc++.h>
using namespace std;
typedef int ll;
struct edge{
    ll to,prev;
};
struct SegmentTree{
    ll l,r,sum,tag;
};
const ll MAXN=1000051;
edge ed[MAXN];
SegmentTree tree[MAXN<<2];
ll last[MAXN],val[MAXN],depth[MAXN],fa[MAXN],size[MAXN],heavy[MAXN];
ll id[MAXN],pre[MAXN],top[MAXN];
ll tot,nc,cnt,root,ccnt,x,y,z,from,to,op;
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
inline void update(ll node)
{
    tree[node].sum=tree[node<<1].sum+tree[(node<<1)|1].sum;
}
inline void create(ll l,ll r,ll node)
{
    tree[node].l=l,tree[node].r=r;
    if(l==r)
    {
        tree[node].sum=0;
        tree[node].tag=-1;
        return;
    }
    ll mid=(l+r)>>1;
    create(l,mid,node<<1);
    create(mid+1,r,(node<<1)|1);
    update(node);
}
inline void spread(ll node)
{
    if(tree[node].tag!=-1)
    {
        tree[node<<1].sum=tree[node].tag*(tree[node<<1].r-tree[node<<1].l+1);
        tree[(node<<1)|1].sum=tree[node].tag*(tree[(node<<1)|1].r-tree[(node<<1)|1].l+1);
        tree[node<<1].tag=tree[node].tag;
        tree[(node<<1)|1].tag=tree[node].tag;
        tree[node].tag=-1;
    }
}
inline void add(ll l,ll r,ll val,ll node)
{
    if(l<=tree[node].l&&r>=tree[node].r)
    {
        tree[node].sum=val*(tree[node].r-tree[node].l+1);
        tree[node].tag=val;
        return;
    }
    spread(node);
    ll mid=(tree[node].l+tree[node].r)>>1;
    if(l<=mid)
    {
        add(l,r,val,node<<1);
    }
    if(r>mid)
    {
        add(l,r,val,(node<<1)|1);
    }
    update(node);
}
inline ll query(ll l,ll r,ll node) 
{
    if(l<=tree[node].l&&r>=tree[node].r)
    {
        return tree[node].sum;
    }
    spread(node);
    ll mid=(tree[node].l+tree[node].r)>>1,val=0;
    if(l<=mid)
    {
        val+=query(l,r,node<<1);
    }
    if(r>mid)
    {
        val+=query(l,r,(node<<1)|1);
    }
    return val;
}
inline void dfs(ll node,ll f,ll dep)
{
    depth[node]=dep,fa[node]=f,size[node]=1;
    ll maxn=-1;
    for(register int i=last[node];i;i=ed[i].prev)
    {
        if(ed[i].to!=f)
        {
            dfs(ed[i].to,node,dep+1);
            size[node]+=size[ed[i].to];
            if(size[ed[i].to]>maxn)
            {
                heavy[node]=ed[i].to,maxn=size[ed[i].to];
            }
        }
    }
}
inline void ddfs(ll node,ll link)
{
    id[node]=++ccnt,val[ccnt]=pre[node],top[node]=link;
    if(!heavy[node])
    {
        return;
    }
    ddfs(heavy[node],link);
    for(register int i=last[node];i;i=ed[i].prev)
    {
        if(ed[i].to!=fa[node]&&ed[i].to!=heavy[node])
        {
            ddfs(ed[i].to,ed[i].to);
        }
    }
}
inline ll queryPath(ll x,ll y)
{
    ll ans=0;
    while(top[x]!=top[y])
    {
        if(depth[top[x]]<depth[top[y]])
        {
            swap(x,y);
        }
        ans+=query(id[top[x]],id[x],1);
        x=fa[top[x]];
    }
    if(depth[x]>depth[y])
    {
        swap(x,y);
    }
    ans+=query(id[x],id[y],1);
    return ans;
}
inline ll querySubtree(ll root)
{
    return query(id[root],id[root]+size[root]-1,1);
}
inline void changePath(ll x,ll y,ll val)
{
    while(top[x]!=top[y])
    {
        if(depth[top[x]]<depth[top[y]])
        {
            swap(x,y);
        }
        add(id[top[x]],id[x],val,1);
        x=fa[top[x]];
    }
    if(depth[x]>depth[y])
    {
        swap(x,y);
    }
    add(id[x],id[y],val,1);
}
inline void changeSubtree(ll root,ll val)
{
    add(id[root],id[root]+size[root]-1,val,1);
}
int main()
{
    nc=read();
    for(register int i=0;i<nc-1;i++)
    {
    	from=read(),to=read();
    	addEdge(from,to),addEdge(to,from);
    }
    dfs(1,0,1),ddfs(1,1),create(1,nc,1);	
    cnt=read();
    for(register int i=0;i<cnt;i++)
    {
        op=read(),x=read();
		switch(op)
		{
			case 1:{
				changeSubtree(x,1);
				break;
			}
			case 2:{
				changePath(x,1,0);
				break;
			}
			case 3:{
				printf("%d\n",queryPath(x,x));
				break;
			}
		} 
    }
}