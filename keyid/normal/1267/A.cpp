#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define pb push_back

const int MAXN=200005;
const LL INF=0x3f3f3f3f3f3f3f3f;

struct interval
{
	LL l,r,t;
}a[MAXN];

struct work
{
	LL fin,t;

	bool operator < (const work &b) const
	{
		return fin!=b.fin?fin<b.fin:t<b.t;
	}
};

int nc;
LL num[MAXN*2];
vector <LL> p[MAXN*2];
vector <work> del[MAXN*2];

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].t);
		num[nc++]=a[i].l;
		num[nc++]=a[i].r+1;
	}
	sort(num,num+nc);
	nc=unique(num,num+nc)-num;
	for (int i=0;i<n;i++)
	{
		a[i].l=lower_bound(num,num+nc,a[i].l)-num;
		a[i].r=lower_bound(num,num+nc,a[i].r+1)-num;
		p[a[i].l].pb(a[i].t);
		del[a[i].r].pb({num[a[i].l]+a[i].t,a[i].t});
	}
	LL ans=0,lst=0;
	multiset <LL> q1;
	multiset <work> q2;
	for (int i=0;i+1<nc;i++)
	{
		LL t=INF;
		for (const auto &v:p[i])
			q2.insert({num[i]+v,v});
		for (const auto &v:del[i])
		{
			if (q2.find(v)!=q2.end())
				q2.erase(q2.find(v));
			else
			{
				assert(q1.find(v.t)!=q1.end());
				q1.erase(q1.find(v.t));
			}
		}
		if (!q1.empty())
			t=min(t,lst+*q1.begin());
		if (!q2.empty())
		{
			if (q2.begin()->fin<num[i])
				for (;;);
			t=min(t,q2.begin()->fin);
		}
		if (t<num[i+1])
		{
			ans++;
			lst=t;
			for (const auto &v:q2)
				q1.insert(v.t);
			q2.clear();
			LL d=num[i+1]-1-t;
			LL k=d/(*q1.begin());
			ans+=k;
			lst+=k*(*q1.begin());
		}
	}
	printf("%lld\n",ans);
	return 0;
}