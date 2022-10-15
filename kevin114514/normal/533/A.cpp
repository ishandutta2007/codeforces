#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
int h[500500];
vector<int> G[500500];
vector<int> vec[500500];
int mn[500500],mn2[500500],mnp[500500];
int s[500500];
void dfs(int u,int fa)
{
	if(h[u]<mn[fa])
	{
		mn[u]=h[u];
		mnp[u]=u;
		mn2[u]=mn[fa];
	}
	else if(h[u]<mn2[fa])
	{
		mn[u]=mn[fa];
		mnp[u]=mnp[fa];
		mn2[u]=h[u];
	}
	else
	{
		mn[u]=mn[fa];
		mnp[u]=mnp[fa];
		mn2[u]=mn2[fa];
	}
	vec[mnp[u]].pb(u);
	for(auto v:G[u]) if(v!=fa)
		dfs(v,u);
}
struct node
{
	int l,r;
	int tag;
	int mn;
	node *lson,*rson;
	node(int _l,int _r)
	{
		l=_l;
		r=_r;
		tag=0;
		mn=0;
		lson=rson=NULL;
	}
};
node *build(int l,int r)
{
	node *rt=new node(l,r);
	if(l!=r)
	{
		int mid=(l+r)/2;
		rt->lson=build(l,mid);
		rt->rson=build(mid+1,r);
	}
	return rt;
}
void pushdown(node *nd)
{
	nd->mn+=nd->tag;
	if(nd->l!=nd->r)
	{
		nd->lson->tag+=nd->tag;
		nd->rson->tag+=nd->tag;
	}
	nd->tag=0;
}
void pushup(node *nd)
{
	if(nd->l!=nd->r)
	{
		pushdown(nd->lson);
		pushdown(nd->rson);
		nd->mn=min(nd->lson->mn,nd->rson->mn);
	}
}
void update(node *nd,int l,int r,int v)
{
	pushdown(nd);
	if(nd->l==l&&nd->r==r)
	{
		nd->tag+=v;
		pushdown(nd);
		pushup(nd);
		return ;
	}
	int mid=(nd->l+nd->r)/2;
	if(r<=mid)
		update(nd->lson,l,r,v);
	else if(l>mid)
		update(nd->rson,l,r,v);
	else
	{
		update(nd->lson,l,mid,v);
		update(nd->rson,mid+1,r,v);
	}
	pushup(nd);
}
int query(node *nd,int l,int r)
{
	pushdown(nd);
	if(nd->l==l&&nd->r==r)
		return nd->mn;
	int mid=(nd->l+nd->r)/2;
	if(r<=mid)
		return query(nd->lson,l,r);
	if(l>mid)
		return query(nd->rson,l,r);
	return min(query(nd->lson,l,mid),query(nd->rson,mid+1,r));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)
		cin>>s[i];
	sort(s+1,s+k+1);
	mn[0]=mn2[0]=inf;
	dfs(1,0);
	node *nd=build(1,k);
	for(int i=1;i<=k;i++)
		update(nd,i,i,i);
	for(int i=1;i<=n;i++)
	{
		int pos=upper_bound(s+1,s+k+1,mn[i])-s-1;
		if(pos)
			update(nd,1,pos,1);
	}
	if(query(nd,1,k)>k)
		die("0");
	int need=0;
	for(int i=1;i<=k;i++)
		if(query(nd,i,i)<=k)
			need=s[i];
	int ans=inf;
	for(int i=1;i<=n;i++) if(need>h[i])
	{
		int mid=need;
		for(auto x:vec[i])
		{
			int pos1=upper_bound(s+1,s+k+1,mn[x])-s-1;
			if(pos1)
				update(nd,1,pos1,-1);
			int pos=upper_bound(s+1,s+k+1,min(mn2[x],mid))-s-1;
			if(pos)
				update(nd,1,pos,1);
		}
		bool f=0;
		if(query(nd,1,k)>k)
			f=1;
		for(auto x:vec[i])
		{
			int pos1=upper_bound(s+1,s+k+1,mn[x])-s-1;
			if(pos1)
				update(nd,1,pos1,1);
			int pos=upper_bound(s+1,s+k+1,min(mn2[x],mid))-s-1;
			if(pos)
				update(nd,1,pos,-1);
		}
		if(f)
			ans=min(ans,need-h[i]);
	}
	if(ans==inf)
		die("-1");
	cout<<ans<<endl;
	return 0;
}