#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005,MAXNUM=MAXN*300;

struct Point
{
	int l,r,y;
}p[MAXN];

int cnt[MAXNUM],num[MAXNUM];
LL ans[MAXN];

bool cmp1(const Point &a,const Point &b)
{
	return a.l<b.l;
}

bool cmp2(const Point &a,const Point &b)
{
	return a.y<b.y;
}

inline void update(int d,int l,int r,int y)
{
	for (int i=l;i<r;i++)
	{
		ans[cnt[i]]+=y-num[i];
		num[i]=y;
		cnt[i]+=d;
	}
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d%d",&p[i].l,&p[i].y);
	sort(p,p+n,cmp1);
	int nc=0,last=INT_MIN;
	for (int i=0;i<n;i++)
	{
		for (last=max(last,p[i].l);last<p[i].l+k;last++)
			num[nc++]=last;
		p[i].l=lower_bound(num,num+nc,p[i].l)-num;
		p[i].r=nc;
	}
	sort(p,p+n,cmp2);
	for (int h1=0,h2=0;h1<n||h2<n;)
		if (h1>=n)
		{
			update(-1,p[h2].l,p[h2].r,p[h2].y+k);
			h2++;
		}
		else if (h2>=n)
		{
			update(1,p[h1].l,p[h1].r,p[h1].y);
			h1++;
		}
		else if (p[h2].y+k<p[h1].y)
		{
			update(-1,p[h2].l,p[h2].r,p[h2].y+k);
			h2++;
		}
		else
		{
			update(1,p[h1].l,p[h1].r,p[h1].y);
			h1++;
		}
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}