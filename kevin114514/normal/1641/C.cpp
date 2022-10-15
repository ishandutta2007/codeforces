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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
struct node
{
	int l,r,val;
	node *lson,*rson;
	node(int _l,int _r)
	{
		l=_l;
		r=_r;
		val=inf;
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
void update(node *nd,int p,int v)
{
	nd->val=min(nd->val,v);
	if(nd->l==nd->r)
		return ;
	int mid=(nd->l+nd->r)/2;
	if(p<=mid)
		update(nd->lson,p,v);
	else	update(nd->rson,p,v);
}
int query(node *nd,int l,int r)
{
	if(nd->l==l&&nd->r==r)
		return nd->val;
	int mid=(nd->l+nd->r)/2;
	if(r<=mid)
		return query(nd->lson,l,r);
	else if(l>mid)
		return query(nd->rson,l,r);
	else	return min(query(nd->lson,l,mid),query(nd->rson,mid+1,r));
}
int main()
{
	int n,q;
	cin>>n>>q;
	set<int> st;
	for(int i=1;i<=n;i++)
		st.insert(i);
	node *rt=build(1,n);
	while(q--)
	{
		int t;
		cin>>t;
		if(!t)
		{
			int l,r,x;
			cin>>l>>r>>x;
			if(x)
				update(rt,l,r);
			else
			{
				auto it=st.lower_bound(l);
				while(it!=st.end()&&*it<=r)
				{
					auto it2=it;
					it2++;
					st.erase(it);
					it=it2;
				}
			}
		}
		else
		{
			int p;
			cin>>p;
			auto it=st.lower_bound(p);
			if(it==st.end()||*it!=p)
				puts("NO");
			else
			{
				int l=0,r=n+1;
				if(it!=st.begin())
				{
					auto it2=it;
					it2--;
					l=*it2;
				}
				{
					auto it2=it;
					it2++;
					if(it2!=st.end())
						r=*it2;
				}
				if(query(rt,l+1,p)<r)
					puts("YES");
				else	puts("N/A");
			}
		}
	}
	return 0;
}