#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000005;

struct query
{
	int a,t,x,id;
}b[MAXN],q[MAXN];

int nc,num[MAXN],cnt[MAXN],ans[MAXN];

bool cmp(const query &b1,const query &b2)
{
	return b1.t!=b2.t?b1.t<b2.t:b1.a<b2.a;
}

void cdq(int l,int r)
{
	if (l==r)
	{
		if (b[l].a==3) printf("%d\n",ans[l]);
		return;
	}
	int m=l+r>>1,h1=l,h2=m;
	for (int i=l;i<=r;i++)
		if (b[i].id<=m)
		{
			q[h1++]=b[i];
			if (b[i].a<3) cnt[b[i].x]+=(b[i].a==1?1:-1);
		}
		else
		{
			q[++h2]=b[i];
			if (b[i].a==3) ans[b[i].id]+=cnt[b[i].x];
		}
	for (int i=l;i<=r;i++) b[i]=q[i];
	for (int i=l;i<h1;i++)
		if (q[i].a<3) cnt[q[i].x]-=(q[i].a==1?1:-1);
	cdq(l,m);
	cdq(m+1,r);
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d%d",&b[i].a,&b[i].t,&b[i].x);
		b[i].id=i;
		num[i]=b[i].x;
	}
	sort(num,num+n);
	nc=unique(num,num+n)-num;
	for (int i=0;i<n;i++) b[i].x=upper_bound(num,num+nc,b[i].x)-num;
	sort(b,b+n,cmp);
	cdq(0,n-1);
	return 0;
}