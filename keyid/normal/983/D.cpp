#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

struct rec
{
	int x1,y1,x2,y2;
}a[MAXN];

struct op
{
	int x,l,r,v;
}d[MAXN*2];

int nc,num[MAXN*3],yl,yr,V,mxv[MAXN*12],mnv[MAXN*12];
bool ok[MAXN];
set <int,greater<int> > cov[MAXN*12];

bool cmp(const op &a,const op &b)
{
	return a.x<b.x;
}

void maintain(int o,int l,int r)
{
	if (l<r)
	{
		int lc=o<<1,rc=o<<1|1;
		mxv[o]=max(mxv[lc],mxv[rc]);
		mnv[o]=min(mnv[lc],mnv[rc]);
		if (!cov[o].empty()&&mnv[o]<*cov[o].begin())
		{
			mnv[o]=*cov[o].begin();
			if (*cov[o].begin()>mxv[o])
				mxv[o]=ok[*cov[o].begin()]?0:*cov[o].begin();
		}
	}
	else if (!cov[o].empty())
	{
		mxv[o]=ok[*cov[o].begin()]?0:*cov[o].begin();
		mnv[o]=*cov[o].begin();
	}
	else
		mxv[o]=mnv[o]=0;
}

void add(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
		cov[o].insert(V);
	else
	{
		int m=l+r>>1;
		if (yl<=m)
			add(o<<1,l,m);
		if (yr>m)
			add(o<<1|1,m+1,r);
	}
	maintain(o,l,r);
}

void del(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
		cov[o].erase(V);
	else
	{
		int m=l+r>>1;
		if (yl<=m)
			del(o<<1,l,m);
		if (yr>m)
			del(o<<1|1,m+1,r);
	}
	maintain(o,l,r);
}

void update(int o,int l,int r)
{
	if (yl>l||yr<r)
	{
		int m=l+r>>1;
		if (yl<=m)
			update(o<<1,l,m);
		if (yr>m)
			update(o<<1|1,m+1,r);
	}
	maintain(o,l,r);
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		num[nc++]=a[i].y1;
		num[nc++]=a[i].y2-1;
		num[nc++]=a[i].y2;
	}
	sort(num,num+nc);
	nc=unique(num,num+nc)-num;
	for (int i=0;i<n;i++)
	{
		a[i].y1=upper_bound(num,num+nc,a[i].y1)-num;
		a[i].y2=upper_bound(num,num+nc,a[i].y2-1)-num;
		d[i<<1]={a[i].x1,a[i].y1,a[i].y2,i+1};
		d[i<<1|1]={a[i].x2,-a[i].y1,-a[i].y2,i+1};
	}
	sort(d,d+2*n,cmp);
	int ans=1;
	for (int i=0;i<2*n;)
	{
		int j;
		for (j=i+1;j<2*n&&d[j].x==d[i].x;j++);
		for (int k=i;k<j;k++)
			if (d[k].l<0)
			{
				yl=-d[k].l;
				yr=-d[k].r;
				V=d[k].v;
				del(1,1,nc);
			}
			else
			{
				yl=d[k].l;
				yr=d[k].r;
				V=d[k].v;
				add(1,1,nc);
			}
		while (mxv[1])
		{
			ans++;
			V=mxv[1];
			ok[V]=true;
			yl=a[V-1].y1;
			yr=a[V-1].y2;
			update(1,1,nc);
		}
		i=j;
	}
	printf("%d",ans);
	return 0;
}