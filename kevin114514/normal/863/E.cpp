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
void die(string S){puts(S.c_str());exit(0);}
struct node
{
	node *lson,*rson;
	int l,r;
	int val;
	node(int _l,int _r)
	{
		val=0;
		l=_l;
		r=_r;
		lson=rson=NULL;
	}
//	void pushup()
//	{
//		if(l!=r)
//			val=min(this->lson->val,this->rson->val);
//	}
};
node *build(int l,int r)
{
	node *nd=new node(l,r);
	if(l!=r)
	{
		int mid=(l+r)/2;
		nd->lson=build(l,mid);
		nd->rson=build(mid+1,r);
	}
	return nd;
}
void update(node *nd,int p,int v)
{
	if(nd->l==nd->r)
	{
		nd->val=v;
		return ;
	}
	int mid=(nd->l+nd->r)/2;
	if(p<=mid)
		update(nd->lson,p,v);
	else	update(nd->rson,p,v);
	nd->val=min(nd->lson->val,nd->rson->val);
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
int l[200200],r[200200];
int delta[1200200];
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",l+i,r+i);
		v.pb(l[i]);
		v.pb(r[i]);
		v.pb(l[i]-1);
		v.pb(l[i]+1);
		v.pb(r[i]-1);
		v.pb(r[i]+1);
	}
	srt(v);
	v.resize(unique(ALL(v))-v.begin());
	for(int i=0;i<n;i++)
	{
		l[i]=lower_bound(ALL(v),l[i])-v.begin()+1;
		r[i]=lower_bound(ALL(v),r[i])-v.begin()+1;
		delta[l[i]]++;
		delta[r[i]+1]--;
	}
	int cnt=0;
	node *segtree=build(1,sz(v));
	for(int i=1;i<=sz(v);i++)
	{
		cnt+=delta[i];
//		cout<<i<<" "<<cnt<<endl;
		update(segtree,i,cnt);
	}
	for(int i=0;i<n;i++)
		if(query(segtree,l[i],r[i])>1)
		{
			cout<<i+1<<endl;
			return 0;
		}
	puts("-1");
	return 0;
}