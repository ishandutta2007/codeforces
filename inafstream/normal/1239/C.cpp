#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

long long n,m,i,j,a[100005],ans[100005],t;
struct pa
{
	long long x,id;
	bool operator <(const pa &t) const
	{
		return id<t.id;
	}
}b[100005],q[100005];
int ql,qr;
set<pa> tq,iq;

bool cmp(pa x,pa y)
{
	if(x.x==y.x) return x.id<y.id;
	return x.x<y.x;
}

void ins(long long id,long long x)
{
	pa t;
	t.x=x+m;t.id=id;
	iq.insert(t);
	q[++qr]=t;
}
bool check(long long x)
{
	if(iq.empty()) return 1;
	long long t=iq.begin()->id;
	return x<t;
}

int main()
{
	scanf("%I64d%I64d",&n,&m);
	rep(i,n)
	{
		scanf("%I64d",&a[i]);
		b[i]=(pa){a[i],i};
	}
	sort(b+1,b+n+1,cmp);
	
	t=0;i=1;
	b[n+1]=(pa){0x3f3f3f3f3f3f3f3fll,-1};
	ql=1;qr=0;
	for(;;)
	{
		if(ql>qr)
		{
			if(i>n) break;
			t=b[i].x;
		}
		else
		{
			t=min(b[i].x,q[ql].x);
		}
		
		if(ql<=qr&&q[ql].x==t)
		{
			iq.erase(q[ql]);
			ans[q[ql].id]=q[ql].x;
			ql++;
			if(ql<=qr) q[ql].x=max(q[ql].x,t+m);
		}
		
		while (i<=n&&b[i].x==t)
		{
			tq.insert(b[i]);
			i++;
		}
		while (!tq.empty()&&check(tq.begin()->id))
		{
			ins(tq.begin()->id,t);
			tq.erase(tq.begin());
		}
	}
	
	rep(i,n)
	{
		printf("%I64d ",ans[i]);
	}
	return 0;
}