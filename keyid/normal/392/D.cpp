#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second

const int MAXN=100005;

struct pos
{
	int a,b,c;

	void update(int n)
	{
		if (a==0)
			a=n;
		if (b==0)
			b=n;
		if (c==0)
			c=n;
	}
}p[MAXN*3];


int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	map <int,pos> ms;
	map <int,int> pa;
	priority_queue <int,vector<int>,greater<int>> q,del;
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if (ms[x].a==0)
			ms[x].a=i;
	}
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if (ms[x].b==0)
			ms[x].b=i;
	}
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if (ms[x].c==0)
			ms[x].c=i;
	}
	int cnt=0;
	for (auto &ps:ms)
	{
		ps.sc.update(n*3);
		p[cnt++]=ps.sc;
	}
	sort(p,p+cnt,[](const auto &x,const auto &y) { return x.a>y.a; });
	int ans=p[0].a;
	pa[0]=INT_MAX;
	pa[INT_MAX]=0;
	q.push(0);
	for (int i=0;i<cnt;i++)
	{
		auto k=pa.lower_bound(p[i].b);
		ans=min(ans,p[i].a+q.top());
		if (k->sc<p[i].c)
		{
			k=pa.upper_bound(p[i].b);
			auto k2=k;
			--k2;
			del.push(k2->fi+k->sc);
			--k;
			while (k->sc<=p[i].c)
			{
				--k2;
				del.push(k2->fi+k->sc);
				pa.erase(k--);
			}
			k=pa.upper_bound(p[i].b);
			q.push(p[i].b+k->sc);
			--k;
			q.push(p[i].c+k->fi);
			pa[p[i].b]=p[i].c;
		}
		while (!del.empty()&&del.top()==q.top())
		{
			del.pop();
			q.pop();
		}
	}
	ans=min(ans,q.top());
	printf("%d",ans);
	return 0;
}