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
	char key,tag;
	int l,r;
	node *lson,*rson;
	node(int _l,int _r)
	{
		l=_l;
		r=_r;
		lson=rson=NULL;
		key='a';
		tag='z';
	}
};
void pushdown(node *nd)
{
	if(nd->tag!='z')
	{
		nd->key=nd->tag;
		if(nd->l!=nd->r)
		{
			nd->lson->tag=nd->tag;
			nd->rson->tag=nd->tag;
		}
		nd->tag='z';
	}
}
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
void update(node *nd,int l,int r,char c)
{
	pushdown(nd);
	if(nd->l==l&&nd->r==r)
	{
		nd->tag=c;
		pushdown(nd);
		return ;
	}
	int mid=(nd->l+nd->r)/2;
	if(r<=mid)
		update(nd->lson,l,r,c);
	else if(l>mid)
		update(nd->rson,l,r,c);
	else
	{
		update(nd->lson,l,mid,c);
		update(nd->rson,mid+1,r,c);
	}
	pushdown(nd);
}
char query(node *nd,int p)
{
	pushdown(nd);
	if(nd->l==nd->r)
		return nd->key;
	int mid=(nd->l+nd->r)/2;
	if(p<=mid)
		return query(nd->lson,p);
	else	return query(nd->rson,p);
}
struct node2
{
	int key[10][10];
	int l,r;
	int tag1,tag2;
	node2 *lson,*rson;
	node2(int _l,int _r)
	{
		l=_l;
		r=_r;
		lson=rson=NULL;
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				key[i][j]=0;
		tag1=tag2=11;
	}
};
node2 *build2(int l,int r)
{
	node2 *rt=new node2(l,r);
	if(l!=r)
	{
		int mid=(l+r)/2;
		rt->lson=build2(l,mid);
		rt->rson=build2(mid+1,r);
	}
	return rt;
}
void pushdown2(node2 *nd)
{
	if(nd==NULL)
		return ;
	if(nd->tag1!=11)
	{
//		pushdown2(nd->lson);
//		pushdown2(nd->rson);
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				nd->key[i][j]=0;
		if(nd->tag1!=10)
			nd->key[nd->tag1][nd->tag2]=nd->r-nd->l+1;
		if(nd->l!=nd->r)
		{
			nd->lson->tag1=nd->tag1;
			nd->lson->tag2=nd->tag2;
			nd->rson->tag1=nd->tag1;
			nd->rson->tag2=nd->tag2;
		}
		nd->tag1=11;
		nd->tag2=11;
	}
}
void pushup2(node2 *nd)
{
	pushdown2(nd);
	if(nd->l!=nd->r)
	{
		pushdown2(nd->lson);
		pushdown2(nd->rson);
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				nd->key[i][j]=nd->lson->key[i][j]+nd->rson->key[i][j];
	}
}
void update2(node2 *nd,int l,int r,int t1=10,int t2=10)
{
	pushdown2(nd);
	if((nd->l==l&&nd->r==r))
	{
		nd->tag1=t1;
		nd->tag2=t2;
		pushdown2(nd);
		return ;
	}
	int mid=(nd->l+nd->r)/2;
	if(r<=mid)
		update2(nd->lson,l,r,t1,t2);
	else if(l>mid)
		update2(nd->rson,l,r,t1,t2);
	else
	{
		update2(nd->lson,l,mid,t1,t2);
		update2(nd->rson,mid+1,r,t1,t2);
	}
	pushup2(nd);
}
void updatesingle(node2 *nd,int p,int a,int b)
{
	pushdown2(nd);
	if(nd->l==nd->r)
	{
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				nd->key[i][j]=0;
		nd->key[a][b]++;
		return ;
	}
	int mid=(nd->l+nd->r)/2;
	if(p<=mid)
		updatesingle(nd->lson,p,a,b);
	else	updatesingle(nd->rson,p,a,b);
	pushup2(nd);
}
char s[200200];
char buf[20];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s+1);
	if(n==1)
	{
		while(m--)
		{
			int tp;
			scanf("%d",&tp);
			if(tp==1)
			{
				int a,b;
				char c;
				scanf("%d %d %c",&a,&b,&c);
			}
			else
			{
				scanf("%s",s);
				puts("1");
			}
		}
		return 0;
	}
	node *segtree=build(1,n);
	node2 *segtree2=build2(1,n-1);
	update2(segtree2,1,n-1);
	for(int i=1;i<=n;i++)
	{
		update(segtree,i,i,s[i]);
		if(i!=n)
			updatesingle(segtree2,i,s[i]-'a',s[i+1]-'a');
	}
	while(m--)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			char c;
			int a,b;
			scanf("%d %d %c",&a,&b,&c);
			update(segtree,a,b,c);
			if(a!=b)
				update2(segtree2,a,b-1,c-'a',c-'a');
			if(a!=1)
			{
				updatesingle(segtree2,a-1,query(segtree,a-1)-'a',query(segtree,a)-'a');
			}
			if(b!=n)
			{
				updatesingle(segtree2,b,query(segtree,b)-'a',query(segtree,b+1)-'a');
			}
		}
		else
		{
			scanf("%s",buf);
			int ans=1;
			for(int i=0;i<k;i++)
				for(int j=i;j<k;j++)
				{
					ans+=segtree2->key[buf[j]-'a'][buf[i]-'a'];
				}
			printf("%d\n",ans);
		}
	}
	return 0;
}