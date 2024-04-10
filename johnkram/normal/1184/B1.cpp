#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
struct node
{
	int a,b;
	bool operator<(const node& y)const
	{
		if(a==y.a)return b>y.b;
		return a<y.a;
	}
}a[MAXN];
int n,m,i,ans[MAXN],h;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i].a);
		a[i].b=-i;
	}
	for(;i<=n+m;i++)scanf("%d%d",&a[i].a,&a[i].b);
	sort(a+1,a+n+m+1);
	for(i=1;i<=n+m;i++)if(a[i].b>=0)h+=a[i].b;
	else ans[-a[i].b]=h;
	for(i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}