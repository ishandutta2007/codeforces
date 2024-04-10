#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define int ll
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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}

struct node
{
	int l,r;
	node *lson,*rson;
	int sum,tag;
	node(int _l,int _r)
	{
		l=_l;
		r=_r;
		sum=tag=0;
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
//void pushup(node *nd)
//{
//	if(nd->l!=nd->r)
//		nd->sum=nd->lson->sum+nd->rson->sum;
//}
void pushdown(node *nd)
{
	nd->sum+=(nd->r-nd->l+1)*nd->tag;
	if(nd->l!=nd->r)
		nd->lson->tag+=nd->tag,
		nd->rson->tag+=nd->tag;
	nd->tag=0;
}
void update(node *nd,int l,int r,int delta)
{
//	cout<<nd->l<<" "<<l<<endl;
//	cout<<nd->r<<" "<<r<<endl;
//	cout<<endl;
	l=max(l,nd->l);
	r=min(r,nd->r);
	if(l>r)
		return ;
	pushdown(nd);
	if(nd->l==l&&nd->r==r)
	{
		nd->tag+=delta;
		pushdown(nd);
		return ;
	}
	else	nd->sum+=(r-l+1)*delta;
	int mid=(nd->l+nd->r)/2;
	if(r<=mid)
		update(nd->lson,l,r,delta);
	else if(l>mid)
		update(nd->rson,l,r,delta);
	else
	{
		update(nd->lson,l,mid,delta);
		update(nd->rson,mid+1,r,delta);
	}
//	pushup(nd);
}
int query(node *nd,int l,int r)
{
//	cout<<nd->l<<" "<<l<<endl;
//	cout<<nd->r<<" "<<r<<endl;
//	cout<<endl;
	l=max(l,nd->l);
	r=min(r,nd->r);
	if(l>r)
		return 0;
	pushdown(nd);
	if(nd->l==l&&nd->r==r)
		return nd->sum;
	int mid=(nd->l+nd->r)/2;
	if(r<=mid)
		return query(nd->lson,l,r);
	else if(l>mid)
		return query(nd->rson,l,r);
	return query(nd->lson,l,mid)+query(nd->rson,mid+1,r);
}

int p[200200],pos[200200];
int l[200200],r[200200];

struct Query
{
	int l,ind;
	Query(int _l,int _ind)
	{
		l=_l;
		ind=_ind;
	}
};
vector<Query> que[200200];

vector<pii> vec[200200];

int ans[1001000];

struct Operation
{
	int tm,l,r,delta;
	Operation(int _tm,int _l,int _r,int _delta)
	{
		tm=_tm;
		l=_l;
		r=_r;
		delta=_delta;
	}
	friend bool operator <(const Operation &a,const Operation &b)
	{
		return a.tm<b.tm;
	}
};

int read()
{
	int x=0;
	char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}

signed main()
{
	int n,q;
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		p[i]=read();
		pos[p[i]]=i;
	}
	for(int i=1;i<=q;i++)
	{
		int l,r;
		l=read();
		r=read();
		que[r].pb(Query(l,i));
	}
	
	for(int i=1;i<=n;i++)
		r[i]=n;
	stack<int> st;
	for(int i=1;i<=n;i++)
	{
		l[i]=i;
		while(!st.empty()&&st.top()<p[i])
		{
			r[pos[st.top()]]=i-1;
			l[i]=l[pos[st.top()]];
			st.pop();
		}
		st.push(p[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		for(int y=1;y*x<=n;y++)
		{
			int l0=pos[y],r0=i;
			if(l0>=r0)
				continue;
			int m0=pos[x*y];
			if(l0<l[m0]||r0>r[m0])
				continue;
			l0=min(l0,m0);
			r0=max(r0,m0);
			if(sz(vec[m0])&&l0<=vec[m0].back().first)
				continue;
			vec[m0].pb(mp(l0,r0));
		}
	}
	
	vector<Operation> vop;
	for(int i=1;i<=n;i++)
		for(int j=0;j<sz(vec[i]);j++)
		{
			int tml=vec[i][j].second;
			int tmr=((j<sz(vec[i])-1)?(vec[i][j+1].second-1):(r[i]));
			int l0=l[i],r0=vec[i][j].first;
			if(tml>tmr)
				continue;
			if(l0>r0)
				continue;
			vop.pb(Operation(tml,l0,r0,1));
			vop.pb(Operation(tmr+1,l0,r0,-1));
		}
	srt(vop);
	
	node *t1=build(1,n);
	node *t2=build(1,n);
	
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		while(pos<sz(vop)&&vop[pos].tm<=i)
		{
			update(t1,vop[pos].l,vop[pos].r,(1-i)*vop[pos].delta);
			update(t2,vop[pos].l,vop[pos].r,vop[pos].delta);
			pos++;
		}
		for(auto qu:que[i])
			ans[qu.ind]=query(t2,qu.l,i)*i+query(t1,qu.l,i);
	}
	
	for(int i=1;i<=q;i++)
		printf("%lld\n",ans[i]);
	
	return 0;
}