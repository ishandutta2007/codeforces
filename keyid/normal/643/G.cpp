#include <bits/stdc++.h>
using namespace std;

const int MAXN=150005;

struct info
{
	int setv,num[5],cnt[5];
}v[MAXN*4],ret;

int p,a[MAXN],yl,yr,V;

void maintain(info &p0,const info &p1,const info &p2)
{
	p0=p1;
	p0.setv=0;
	for (int i=0;i<p;i++)
	{
		if (!p2.cnt[i])
			continue;
		bool flag=false;
		for (int j=0;j<p;j++)
			if (p0.num[j]==p2.num[i])
			{
				p0.cnt[j]+=p2.cnt[i];
				flag=true;
				break;
			}
		if (flag)
			continue;
		int mn=INT_MAX;
		for (int j=0;j<p;j++)
		{
			if (p0.cnt[j]==0)
			{
				p0.num[j]=p2.num[i];
				p0.cnt[j]=p2.cnt[i];
				flag=true;
				break;
			}
			mn=min(mn,p0.cnt[j]);
		}
		if (flag)
			continue;
		if (mn>=p2.cnt[i])
		{
			for (int j=0;j<p;j++)
				p0.cnt[j]-=p2.cnt[i];
		}
		else
		{
			for (int j=0;j<p;j++)
				p0.cnt[j]-=mn;
			for (int j=0;j<p;j++)
				if (p0.cnt[j]==0)
				{
					p0.num[j]=p2.num[i];
					p0.cnt[j]=p2.cnt[i]-mn;
					break;
				}
		}
	}
}

void build(int o,int l,int r)
{
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		build(lc,l,m);
		build(rc,m+1,r);
		maintain(v[o],v[lc],v[rc]);
	}
	else
	{
		v[o].num[0]=a[l];
		v[o].cnt[0]=1;
	}
}

void Set_Value(info &v,int len,int V)
{
	v.setv=V;
	for (int i=1;i<p;i++)
		v.cnt[i]=0;
	v.num[0]=V;
	v.cnt[0]=len;
}

void update(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
		Set_Value(v[o],r-l+1,V);
	else
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		if (v[o].setv)
		{
			Set_Value(v[lc],m-l+1,v[o].setv);
			Set_Value(v[rc],r-m,v[o].setv);
			v[o].setv=0;
		}
		if (yl<=m)
			update(lc,l,m);
		if (yr>m)
			update(rc,m+1,r);
		maintain(v[o],v[lc],v[rc]);
	}
}

void query(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
		maintain(ret,ret,v[o]);
	else
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		if (v[o].setv)
		{
			Set_Value(v[lc],m-l+1,v[o].setv);
			Set_Value(v[rc],r-m,v[o].setv);
			v[o].setv=0;
		}
		if (yl<=m)
			query(lc,l,m);
		if (yr>m)
			query(rc,m+1,r);
	}
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d%d%d",&n,&m,&p);
	p=100/p;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	while (m--)
	{
		int op;
		scanf("%d%d%d",&op,&yl,&yr);
		if (op==1)
		{
			scanf("%d",&V);
			update(1,1,n);
		}
		else
		{
			for (int i=0;i<p;i++)
				ret.cnt[i]=0;
			query(1,1,n);
			int ans=0;
			for (int i=0;i<p;i++)
				if (ret.cnt[i])
					ans++;
			printf("%d",ans);
			for (int i=0;i<p;i++)
				if (ret.cnt[i])
					printf(" %d",ret.num[i]);
			puts("");
		}
	}
	return 0;
}