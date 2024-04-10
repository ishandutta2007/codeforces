#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=200005,MOD=998244353;

set <pii> seg[MAXN];

int yl,yr,V,addv[MAXN*4],mul[MAXN*4],sum[MAXN*4];
pii t[MAXN];

void build(int o,int l,int r)
{
	mul[o]=1;
	if (l<r)
	{
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
	}
}

void push_down(int o,int l,int r,int m,int lc,int rc)
{
	mul[lc]=(LL)mul[lc]*mul[o]%MOD;
	mul[rc]=(LL)mul[rc]*mul[o]%MOD;
	addv[lc]=((LL)addv[lc]*mul[o]+addv[o])%MOD;
	addv[rc]=((LL)addv[rc]*mul[o]+addv[o])%MOD;
	sum[lc]=((LL)sum[lc]*mul[o]+(LL)addv[o]*(m-l+1))%MOD;
	sum[rc]=((LL)sum[rc]*mul[o]+(LL)addv[o]*(r-m))%MOD;
	mul[o]=1;
	addv[o]=0;
}

void update_add(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
	{
		addv[o]=(addv[o]+1)%MOD;
		sum[o]=(sum[o]+r-l+1)%MOD;
	}
	else
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		push_down(o,l,r,m,lc,rc);
		if (yl<=m)
			update_add(lc,l,m);
		if (yr>m)
			update_add(rc,m+1,r);
		sum[o]=(sum[lc]+sum[rc])%MOD;
	}
}

void update_mul(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
	{
		addv[o]=addv[o]*2%MOD;
		mul[o]=mul[o]*2%MOD;
		sum[o]=sum[o]*2%MOD;
	}
	else
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		push_down(o,l,r,m,lc,rc);
		if (yl<=m)
			update_mul(lc,l,m);
		if (yr>m)
			update_mul(rc,m+1,r);
		sum[o]=(sum[lc]+sum[rc])%MOD;
	}
}

void query(int o,int l,int r)
{
	if (yl<=l&&yr>=r)
		V=(V+sum[o])%MOD;
	else
	{
		int m=l+r>>1,lc=o<<1,rc=o<<1|1;
		push_down(o,l,r,m,lc,rc);
		if (yl<=m)
			query(lc,l,m);
		if (yr>m)
			query(rc,m+1,r);
	}
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	build(1,1,n);
	while (q--)
	{
		int op;
		scanf("%d",&op);
		if (op==2)
		{
			scanf("%d%d",&yl,&yr);
			V=0;
			query(1,1,n);
			printf("%d\n",V);
		}
		else
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			auto &s=seg[x];
			int cnt=0;
			if (!s.empty())
			{
				auto k=s.lower_bound(mp(l,0));
				if (k!=s.begin())
					--k;
				for (;k!=s.end()&&k->fi<=r;)
					if (k->fi<=r&&k->sc>=l)
					{
						t[cnt++]=*k;
						s.erase(k++);
					}
					else
						++k;
				for (int i=0;i<cnt;i++)
				{
					if (t[i].fi<l)
					{
						s.insert(mp(t[i].fi,l-1));
						t[i].fi=l;
					}
					if (t[i].sc>r)
					{
						s.insert(mp(r+1,t[i].sc));
						t[i].sc=r;
					}
				}
				for (int i=0;i<cnt;i++)
				{
					yl=t[i].fi;
					yr=t[i].sc;
					update_mul(1,1,n);
				}
				for (int i=0;i+1<cnt;i++)
				{
					yl=t[i].sc+1;
					yr=t[i+1].fi-1;
					if (yl<=yr)
						update_add(1,1,n);
				}
			}
			// for (int i=0;i<cnt;i++)
			// 	assert(t[i].fi>=l&&t[i].sc<=r&&t[i].fi<=t[i].sc);
			// for (int i=1;i<cnt;i++)
			// 	assert(t[i].fi>t[i-1].sc);
			if (cnt==0)
			{
				yl=l;
				yr=r;
				update_add(1,1,n);
			}
			else
			{
				if (t[0].fi>l)
				{
					yl=l;
					yr=t[0].fi-1;
					update_add(1,1,n);
				}
				if (t[cnt-1].sc<r)
				{
					yl=t[cnt-1].sc+1;
					yr=r;
					update_add(1,1,n);
				}
			}
			s.insert(mp(l,r));
		}
	}
	return 0;
}