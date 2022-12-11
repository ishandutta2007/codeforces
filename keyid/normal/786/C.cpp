#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=100005;

struct Node
{
	Node *ch[2];
	int size;
}pool[MAXN*20],*null,*sz,*root[MAXN];

int n,P,V,a[MAXN],lst[MAXN],pre2[MAXN];
vector <int> pre[MAXN];

Node *update(Node *o,int l,int r,int x)
{
	Node *now=sz++;
	now->size=o->size+1;
	if (l<r)
	{
		int m=l+r>>1;
		if (x<=m)
		{
			now->ch[0]=update(o->ch[0],l,m,x);
			now->ch[1]=o->ch[1];
		}
		else
		{
			now->ch[0]=o->ch[0];
			now->ch[1]=update(o->ch[1],m+1,r,x);
		}
	}
	return now;
}

void getsum(Node *o,int l,int r)
{
	if (r<=P)
		V+=o->size;
	else
	{
		int m=l+r>>1;
		getsum(o->ch[0],l,m);
		if (P>m) getsum(o->ch[1],m+1,r);
	}
}

int query(Node *o,int l,int r,int k)
{
	if (l==r) return l;
	int m=l+r>>1;
	if (o->ch[0]->size>k||(o->ch[0]->size==k&&pre2[m+1]<=P)) return query(o->ch[0],l,m,k);
	return query(o->ch[1],m+1,r,k-o->ch[0]->size);
}

int query(int dis,int fro,int sum)
{
	P=fro-1;
	V=0;
	if (P) getsum(root[dis],1,n);
	sum+=V;
	//printf("%d %d %d\n",fro,V,sum);
	return query(root[dis],1,n,sum);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		pre[lst[a[i]]].pb(i);
		pre2[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	sz=pool;
	null=sz++;
	null->ch[0]=null->ch[1]=null;
	root[0]=null;
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<pre[i].size();j++)
			root[i]=update(root[i],1,n,pre[i][j]);
		root[i+1]=root[i];
	}
	for (int k=1;k<=n;k++)
	{
		int ans=0;
		for (int j=1;j<=n;)
		{
			ans++;
			j=query(j-1,j,k)+1;
		}
		printf("%d ",ans);
	}
	return 0;
}