#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,l[200005],r[200005],a[200005];
struct seg
{
	int l,r,s,fg;
	void update(int x)
	{
		s=fg=x;
	}
}tr[800005];
void pushup(int x)
{
	if (tr[x*2].s==0)
	{
		tr[x].s=tr[x*2+1].s;
		return;
	}
	if (tr[x*2+1].s==0)
	{
		tr[x].s=tr[x*2].s;
		return;
	}
	if (tr[x*2].s!=tr[x*2+1].s)
	{
		tr[x].s=-1;
		return;
	}
	tr[x].s=tr[x*2].s;
}
void pushdo(int x)
{
	if (tr[x].fg!=-1)
	{
		tr[x*2].update(tr[x].fg);
		tr[x*2+1].update(tr[x].fg);
		tr[x].fg=-1;
	}
}
void build(int x,int l,int r)
{
	tr[x].l=l;tr[x].r=r;tr[x].fg=-1;
	if (l==r) tr[x].s=a[l];
	else
	{
		build(x*2,l,(l+r)/2);
		build(x*2+1,(l+r)/2+1,r);
		pushup(x);
	}
}
void update(int x,int l,int r,int c)
{
	if (tr[x].l>r||tr[x].r<l) return;
	if (tr[x].l>=l&&tr[x].r<=r)
	{
		tr[x].update(c);
		return;
	}
	pushdo(x);
	update(x*2,l,r,c);
	update(x*2+1,l,r,c);
	pushup(x);
}
int query(int x,int l,int r)
{
	if (tr[x].l>r||tr[x].r<l) return 0;
	if (tr[x].l>=l&&tr[x].r<=r)
	{
		return tr[x].s;
	}
	pushdo(x);
	int t1=query(x*2,l,r);
	int t2=query(x*2+1,l,r);
	if (t1==0)
	{
		return t2;
	}
	if (t2==0)
	{
		return t1;
	}
	if (t1!=t2) return -1;
	return t1;
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(l,22,sizeof(l));
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		l[a[i]]=min(l[a[i]],i);
		r[a[i]]=max(r[a[i]],i);
	}
	build(1,1,n);
//	l[1]=1;r[1]=n;
	for (i=m;i>=1;i--)
	{
		if (l[i]<=r[i])
		{
			int t=query(1,l[i],r[i]);
			if (t!=0&&t!=i)
			{
				puts("NO");
				return 0;
			}
			update(1,l[i],r[i],0);
		}
	}
	for (i=1;i<=m;i++)
	{
		if (l[i]<=r[i])
		{
			update(1,l[i],r[i],i);
		}
	}
	if (l[m]>r[m])
	{
		for (i=1;i<=n;i++) if (a[i]==0)
		{
			update(1,i,i,m);
			break;
		}
		if (i>n)
		{
			puts("NO");
			return 0;
		}
	}
	for (i=1;i<=n;i++) if (query(1,i,i)==0) update(1,i,i,1);
	puts("YES");
	for (i=1;i<=n;i++)
	{
		printf("%d ",query(1,i,i));
	}
	return 0;
}