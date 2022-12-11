#include <bits/stdc++.h>
using namespace std;

const int MAXN=300005;

typedef long long LL;

struct team
{
	LL t,w;
}a[MAXN];

multiset <LL> s;

bool cmp(const team &a,const team &b)
{
	return a.t>b.t;
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lld%lld",&a[i].t,&a[i].w);
	sort(a+1,a+n,cmp);
	int head=1;
	while (head<n&&a[head].t>a[0].t)
	{
		s.insert(a[head].w-a[head].t+1);
		head++;
	}
	int ans=s.size();
	for (;;)
	{
		if (s.empty()||a[0].t<*s.begin()) break;
		a[0].t-=*s.begin();
		s.erase(s.begin());
		while (head<n&&a[head].t>a[0].t)
		{
			s.insert(a[head].w-a[head].t+1);
			head++;
		}
		if (s.size()<ans)
			ans=s.size();
	}
	printf("%d",ans+1);
	return 0;
}