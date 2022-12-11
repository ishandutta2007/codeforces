#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=100005,MAXM=300005;

struct query
{
	int pos,id;
};

int n,a[MAXN],b[MAXN],nc,num[MAXN],C[MAXN],ans[MAXM],V,yl,yr,valv[MAXN*4];
vector <query> q1[MAXN],q2[MAXN];

void build(int o,int l,int r)
{
	valv[o]=INT_MAX;
	if (l<r)
	{
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
	}
}

void query_max(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
		V=max(V,valv[o]);
	else
	{
		int m=l+r>>1;
		if (yl<=m) query_max(o<<1,l,m);
		if (yr>m) query_max(o<<1|1,m+1,r);
	}
}

void query_min(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
		V=min(V,valv[o]);
	else
	{
		int m=l+r>>1;
		if (yl<=m) query_min(o<<1,l,m);
		if (yr>m) query_min(o<<1|1,m+1,r);
	}
}

void update_max(int o,int l,int r)
{
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		if (yr<=m) update_max(lc,l,m);
		else update_max(rc,m+1,r);
		valv[o]=max(valv[lc],valv[rc]);
	}
	else
		valv[o]=V;
}

void update_min(int o,int l,int r)
{
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		if (yr<=m) update_min(lc,l,m);
		else update_min(rc,m+1,r);
		valv[o]=min(valv[lc],valv[rc]);
	}
	else
		valv[o]=V;
}

void update_front(int x,int d)
{
	for (;x;x-=x&-x)
		C[x]=min(C[x],d);
}

void update_back(int x,int d)
{
	for (;x<=n;x+=x&-x)
		C[x]=min(C[x],d);
}

int getans_front(int x)
{
	int ret=INT_MAX;
	for (;x<=n;x+=x&-x)
		ret=min(ret,C[x]);
	return ret;
}

int getans_back(int x)
{
	int ret=INT_MAX;
	for (;x;x-=x&-x)
		ret=min(ret,C[x]);
	return ret;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[i]=a[i];
	}
	sort(num+1,num+n+1);
	nc=unique(num+1,num+n+1)-num;
	for (int i=1;i<=n;i++)
		b[i]=lower_bound(num+1,num+nc,a[i])-num;
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		q1[r].pb((query){l,i});
		q2[l].pb((query){r,i});
	}
	fill(ans,ans+m,INT_MAX);
	fill(C+1,C+n+1,INT_MAX);
	for (int i=1;i<=n;i++)
	{
		V=0;
		yl=1;
		yr=b[i];
		query_max(1,1,nc-1);
		if (V)
		{
			update_front(V,a[i]-a[V]);
			for (;;)
			{
				yl=upper_bound(num+1,num+nc,(a[i]+a[V])/2)-num;
				if (yl>yr)
					break;
				V=0;
				query_max(1,1,nc-1);
				if (!V) break;
				update_front(V,a[i]-a[V]);
			}
		}
		for (int j=0;j<q1[i].size();j++)
			ans[q1[i][j].id]=getans_front(q1[i][j].pos);
		V=i;
		update_max(1,1,nc-1);
	}
	build(1,1,nc-1);
	fill(C+1,C+n+1,INT_MAX);
	for (int i=n;i>=1;i--)
	{
		V=INT_MAX;
		yl=1;
		yr=b[i];
		query_min(1,1,nc-1);
		if (V<=n)
		{
			update_back(V,a[i]-a[V]);
			for (;;)
			{
				yl=upper_bound(num+1,num+nc,(a[i]+a[V])/2)-num;
				if (yl>yr)
					break;
				V=INT_MAX;
				query_min(1,1,nc-1);
				if (V>n) break;
				update_back(V,a[i]-a[V]);
			}
		}
		for (int j=0;j<q2[i].size();j++)
			ans[q2[i][j].id]=min(ans[q2[i][j].id],getans_back(q2[i][j].pos));
		V=i;
		update_min(1,1,nc-1);
	}
	for (int i=0;i<m;i++)
		printf("%d\n",ans[i]);
	return 0;
}