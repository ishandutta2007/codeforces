#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005,B=550,BC=(MAXN/B)+1;

struct BlockCnt
{
	int f[MAXN],g[BC];

	void add(int p,int d)
	{
		f[p]+=d;
		g[(p-1)/B]+=d;
	}

	void query(int k,int &p,int &s)
	{
		s=k;
		for (int i=0;;i++)
		{
			if ((i+1)*B+g[i]>=s)
				for (int j=i*B+1;;j++)
				{
					if (j+f[j]>=s)
					{
						p=j;
						return;
					}
					s-=f[j];
				}
			s-=g[i];
		}
	}
}cnt[BC];

struct TransInfo
{
	int v1[MAXN],v2[BC];

	void add(int k,int d)
	{
		v1[k]+=d;
	}

	void add(int l,int r,int d)
	{
		int lc=(l-1)/B,rc=(r-1)/B;
		if (lc==rc)
			for (int i=l;i<=r;i++)
				v1[i]+=d;
		else
		{
			for (int i=l;;i++)
			{
				v1[i]+=d;
				if (i%B==0)
					break;
			}
			for (int i=r;;i--)
			{
				v1[i]+=d;
				if (i%B==1)
					break;
			}
			for (int i=lc+1;i<rc;i++)
				v2[i]+=d;
		}
	}
}tr[BC];

int n,b[MAXN],mn[MAXN],rmd[MAXN],cnt_mod[MAXN];

void build(int k,int l,int r)
{
	for (int i=l;i<=r;i++)
	{
		cnt[k].query(b[i],mn[i],rmd[i]);
		tr[k].v1[mn[i]]++;
		cnt[k].add(mn[i],1);
	}
	for (int i=2;i<=n;i++)
		tr[k].v1[i]+=tr[k].v1[i-1];
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		b[i]=i-b[i];
	}
	for (int i=1;i<=n;i+=B)
		build((i-1)/B,i,min(i+B-1,n));
	int m;
	scanf("%d",&m);
	while (m--)
	{
		int op;
		scanf("%d",&op);
		if (op==1)
		{
			int p,v;
			scanf("%d%d",&p,&v);
			v=p-v;
			if (b[p]==v)
				continue;
			int k=(p-1)/B,r=min(n,(k+1)*B);
			for (int i=r;i>=p;i--)
				cnt[k].add(mn[i],-1);
			int mnp,rmdp;
			cnt[k].query(v,mnp,rmdp);
			if (mn[p]==mnp)
				for (int i=p;i<=r;i++)
					cnt[k].add(mn[i],1);
			else if (mn[p]<mnp)
			{
				tr[k].add(mn[p],mnp-1,-1);
				cnt[k].add(mnp,1);
				for (int i=p+1;i<=r;i++)
				{
					int d=cnt_mod[mn[i]-1]+(mn[p]<mn[i]&&mnp>=mn[i]?1:0);
					if (mn[i]+cnt[k].f[mn[i]]<rmd[i]+d)
					{
						rmd[i]=rmd[i]-cnt[k].f[mn[i]]+d;
						cnt_mod[mn[i]]++;
						tr[k].add(mn[i]++,-1);
					}
					else
						rmd[i]+=d;
					cnt[k].add(mn[i],1);
				}
				for (int i=p+1;i<=r;i++)
					cnt_mod[mn[i]-1]=0;
			}
			else
			{
				tr[k].add(mnp,mn[p]-1,1);
				cnt[k].add(mnp,1);
				for (int i=p+1;i<=r;i++)
				{
					int d=cnt_mod[mn[i]]+(mn[p]>=mn[i]&&mnp<mn[i]?1:0);
					if (mn[i]-1+d>=rmd[i])
					{
						rmd[i]=rmd[i]+cnt[k].f[mn[i]-1]-d;
						cnt_mod[mn[i]]++;
						tr[k].add(--mn[i],1);
					}
					else
						rmd[i]-=d;
					cnt[k].add(mn[i],1);
				}
				for (int i=p+1;i<=r;i++)
					cnt_mod[mn[i]+1]=0;
			}
			b[p]=v;
			mn[p]=mnp;
			rmd[p]=rmdp;
		}
		else
		{
			int p;
			scanf("%d",&p);
			int k=b[p];
			for (int r=min(((p-1)/B+1)*B,n),i=p+1;i<=r;i++)
				if (b[i]<=k)
					k++;
			for (int i=(p-1)/B+1;i*B<n;i++)
				k+=tr[i].v1[k]+tr[i].v2[(k-1)/B];
			printf("%d\n",k);
		}
	}
	return 0;
}