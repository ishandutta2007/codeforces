#include <bits/stdc++.h>
using namespace std;

const int MAXN=3005;

struct person
{
	int a,b,id;
}p[MAXN];

int r[MAXN];

bool cmp(const person &a,const person &b)
{
	return a.a!=b.a?a.a>b.a:a.b>b.b;
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i].a);
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i].b);
	for (int i=1;i<=n;i++)
		p[i].id=i;
	sort(p+1,p+n+1,cmp);
	int sum=0,hpsum=0,ret=0,ans=0,pos;
	priority_queue <int> q;
	for (int i=n;i>x+y;i--)
	{
		sum+=p[i].b;
		q.push(p[i].b);
	}
	hpsum=sum;
	for (int i=x+y;i>=x;i--)
	{
		sum+=p[i].b;
		hpsum+=p[i].b;
		q.push(p[i].b);
		if (q.size()>n-x-y)
		{
			hpsum-=q.top();
			q.pop();
		}
		r[i]=sum-hpsum;
	}
	while (!q.empty())
		q.pop();
	sum=0;
	for (int i=1;i<x;i++)
	{
		sum+=p[i].b-p[i].a;
		ret+=p[i].a;
		q.push(p[i].b-p[i].a);
	}
	hpsum=sum;
	for (int i=x;i<=x+y;i++)
	{
		sum+=p[i].b-p[i].a;
		hpsum+=p[i].b-p[i].a;
		ret+=p[i].a;
		q.push(p[i].b-p[i].a);
		if (q.size()>x)
		{
			hpsum-=q.top();
			q.pop();
		}
		if (r[i+1]+ret+sum-hpsum>ans)
		{
			ans=r[i+1]+ret+sum-hpsum;
			pos=i;
		}
	}
	printf("%d\n",ans);
	sort(p+1,p+pos+1,[](const auto & x,const auto & y) { return x.b-x.a<y.b-y.a;} );
	for (int i=1;i<=x;i++)
		printf("%d ",p[i].id);
	puts("");
	for (int i=x+1;i<=pos;i++)
		printf("%d ",p[i].id);
	sort(p+pos+1,p+n+1,[](const auto & x,const auto & y) { return x.b>y.b;} );
	for (int i=pos+1;i<=x+y;i++)
		printf("%d ",p[i].id);
	return 0;
}