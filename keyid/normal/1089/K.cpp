#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=300005,MAXL=1000005;

struct operation
{
	int a,b;
}op[MAXN];

int Y,val[MAXL];
LL MX,V,sumv[MAXL*4],maxv[MAXL*4];

void build(int o,int l,int r)
{
	maxv[o]=r;
	if (l<r)
	{
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
	}
}

void update(int o,int l,int r)
{
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		if (Y<=m)
			update(lc,l,m);
		else
			update(rc,m+1,r);
		sumv[o]=sumv[lc]+sumv[rc];
		maxv[o]=max(maxv[lc],maxv[rc]-sumv[lc]);
	}
	else
	{
		sumv[o]=V;
		maxv[o]=l-V;
	}
}

void query(int o,int l,int r,LL s)
{
	if (l<r)
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		if (Y<=m)
			query(lc,l,m,s);
		else
		{
			V+=sumv[lc];
			MX=max(MX,maxv[lc]-s);
			query(rc,m+1,r,s+sumv[lc]);
		}
	}
	else
	{
		V+=sumv[o];
		MX=max(MX,maxv[o]-s);
	}

}

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	char op_ty[10];
	build(1,0,1000000);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",op_ty);
		if (op_ty[0]=='+')
		{
			scanf("%d%d",&op[i].a,&op[i].b);
			Y=op[i].a;
			V=op[i].b;
			val[Y]=V;
			update(1,0,1000000);
		}
		else if (op_ty[0]=='-')
		{
			int x;
			scanf("%d",&x);
			Y=op[x].a;
			V=0;
			val[Y]=0;
			update(1,0,1000000);
		}
		else
		{
			int x;
			scanf("%d",&x);
			Y=x-1;
			V=0;
			MX=0;
			query(1,0,1000000,0);
			V+=val[x];
			printf("%lld\n",1+MX+V-x);
		}
	}
	return 0;
}