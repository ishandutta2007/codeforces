#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=1005;

struct result
{
	LL l,r;
}ans[MAXN];

mt19937 gen(time(NULL));
LL L;
int id[MAXN],tmp[MAXN];

LL query(int f,LL p)
{
	printf("? %d %lld\n",f,p);
	fflush(stdout);
	LL v;
	scanf("%lld",&v);
	return v;
}

LL get_pos(int x,LL l,LL r,LL v)
{
	while (l<=r)
	{
		LL m=l+r>>1;
		LL val=query(x,m);
		if (val>=v)
			r=m-1;
		else
			l=m+1;
	}
	return l;
}

void solve(int fl,int fr,LL wl,LL wr)
{
	if (fl==fr)
	{
		ans[id[fl]]={wl,wr};
		return;
	}
	int l=fl,r=fr,m=(fl+fr)/2;
	LL V=m*L,p;
	for (;;)
	{
		int x=uniform_int_distribution <int> (l,r) (gen);
		p=get_pos(id[x],wl,wr,V);
		int h1=l,h2=r;
		vector <int> eq;
		for (int i=l;i<=r;i++)
			if (i!=x)
			{
				LL val=query(id[i],p);
				if (val<V)
					tmp[h2--]=id[i];
				else if (val>V)
					tmp[h1++]=id[i];
				else
					eq.push_back(id[i]);
			}
		eq.push_back(id[x]);
		int th=h1;
		for (int &x:eq)
			tmp[th++]=x;
		for (int i=l;i<=r;i++)
			id[i]=tmp[i];
		if (m>=h1&&m<=h2)
			break;
		if (m<h1)
			r=h1-1;
		else
			l=h2+1;
	}
	solve(fl,m,wl,p);
	solve(m+1,fr,p,wr);
}

int main()
{
	int n;
	scanf("%d%lld",&n,&L);
	L/=n;
	for (int i=1;i<=n;i++)
		id[i]=i;
	solve(1,n,0,1000000000000000000);
	puts("!");
	for (int i=1;i<=n;i++)
		printf("%lld %lld\n",ans[i].l,ans[i].r);
	return 0;
}