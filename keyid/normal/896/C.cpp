#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second

typedef long long LL;

const int MAXN=100005,MOD=1000000007;

struct val
{
	LL a;
	int cnt;
}v[MAXN];

int seed,vmax;
map <int,LL> seg;

bool cmp(const val &a,const val &b)
{
	return a.a<b.a;
}

int rnd()
{
	int ret=seed;
	seed=(seed*7LL+13)%MOD;
	return ret;
}

int quick_pow(LL a,int x,int MOD)
{
	int ret=1;
	a%=MOD;
	while (x)
	{
		if (x&1) ret=ret*a%MOD;
		a=a*a%MOD;
		x>>=1;
	}
	return ret;
}

int main()
{
	int n,m;
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	for (int i=1;i<=n;i++)
		seg[i]=rnd()%vmax+1;
	seg[n+1]=0;
	while (m--)
	{
		int op=rnd()%4,l=rnd()%n+1,r=rnd()%n+1,x,y;
		if (l>r)
			swap(l,r);
		if (op==2)
			x=rnd()%(r-l+1)+1;
		else
			x=rnd()%vmax+1;
		if (op==3)
			y=rnd()%vmax+1;
		auto it=--seg.upper_bound(l);
		seg[l]=it->sc;
		it=--seg.upper_bound(r+1);
		seg[r+1]=it->sc;
		if (op==0)
		{
			for (it=seg.lower_bound(l);it->fi<=r;++it)
				it->sc+=x;
		}
		else if (op==1)
		{
			for (it=seg.lower_bound(l);it->fi<=r;)
				seg.erase(it++);
			seg[l]=x;
		}
		else if (op==2)
		{
			int cnt=0;
			for (it=seg.lower_bound(l);it->fi<=r;)
			{
				auto t=it;
				++t;
				v[cnt++]={it->sc,t->fi-it->fi};
				it=t;
			}
			sort(v,v+cnt,cmp);
			int sum=0;
			for (int i=0;i<cnt;i++)
			{
				sum+=v[i].cnt;
				if (sum>=x)
				{
					printf("%lld\n",v[i].a);
					break;
				}
			}
		}
		else
		{
			int ans=0;
			for (it=seg.lower_bound(l);it->fi<=r;)
			{
				auto t=it;
				++t;
				ans=(ans+(LL)quick_pow(it->sc,x,y)*(t->fi-it->fi))%y;
				it=t;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}