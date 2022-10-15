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
void die(string S){puts(S.c_str());exit(0);}
struct node
{
	ll sum,mx;
	int l,r;
	node *lson,*rson;
	node(int _l,int _r)
	{
		l=_l;
		r=_r;
		lson=rson=NULL;
		sum=mx=0;
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
void pushup(node *nd)
{
	nd->mx=max(nd->lson->mx,nd->rson->mx);
	nd->sum=nd->lson->sum+nd->rson->sum;
}
void update_mod(node *nd,int l,int r,int x)
{
	if(nd->mx<x)
		return ;
	if(nd->l==nd->r)
	{
		nd->sum%=x;
		nd->mx%=x;
		return ;
	}
	int mid=(nd->l+nd->r)/2;
	if(r<=mid)
		update_mod(nd->lson,l,r,x);
	else if(l>mid)
		update_mod(nd->rson,l,r,x);
	else
	{
		update_mod(nd->lson,l,mid,x);
		update_mod(nd->rson,mid+1,r,x);
	}
	pushup(nd);
}
void update_set(node *nd,int p,int x)
{
	if(nd->l==nd->r)
	{
		nd->sum=x;
		nd->mx=x;
		return ;
	}
	int mid=(nd->l+nd->r)/2;
	if(p<=mid)
		update_set(nd->lson,p,x);
	else
		update_set(nd->rson,p,x);
	pushup(nd);
}
ll query(node *nd,int l,int r)
{
	if(nd->l==l&&nd->r==r)
		return nd->sum;
	int mid=(nd->l+nd->r)/2;
	if(r<=mid)
		return query(nd->lson,l,r);
	else if(l>mid)
		return query(nd->rson,l,r);
	else return query(nd->lson,l,mid)+query(nd->rson,mid+1,r);
}
int main()
{
	int n,m;
	cin>>n>>m;
	node *rt=build(1,n);
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		update_set(rt,i,x);
	}
	while(m--)
	{
		int tp;
		cin>>tp;
		if(tp==1)
		{
			int l,r;
			cin>>l>>r;
			cout<<query(rt,l,r)<<endl;
		}
		if(tp==2)
		{
			int l,r,x;
			cin>>l>>r>>x;
			update_mod(rt,l,r,x);
		}
		if(tp==3)
		{
			int k,x;
			cin>>k>>x;
			update_set(rt,k,x);
		}
	}
	return 0;
}