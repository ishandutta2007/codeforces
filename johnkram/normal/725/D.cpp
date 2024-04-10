#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
#define ll long long
#define MAXN 300005
struct node
{
	ll a,b;
	bool operator<(const node& y)const
	{
		return b>y.b;
	}
}x,y,a[MAXN];
priority_queue<node> h;
bool cmp(node x,node y)
{
	return x.a>y.a;
}
int n,i,ans;
int main()
{
	cin>>n>>x.a>>x.b;
	for(i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&a[i].a,&a[i].b);
		a[i].b-=a[i].a-1;
	}
	sort(a+1,a+n,cmp);
	for(i=1;i<n;i++)if(a[i].a>x.a)h.push(a[i]);
	else break;
	for(ans=h.size();!h.empty();)
	{
		y=h.top();
		if(y.b>x.a)break;
		x.a-=y.b;
		h.pop();
		for(;i<n;i++)if(a[i].a>x.a)h.push(a[i]);
		else break;
		if(h.size()<ans)ans=h.size();
	}
	cout<<ans+1<<endl;
	return 0;
}