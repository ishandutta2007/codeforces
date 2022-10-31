// Hydro submission #62d4a594b36e4a12382db97e@1658103189006
#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,p,s,e,f;
}a[100001];
bool cmp1(node x,node y)
{
	return x.v!=y.v?x.v<y.v:x.f>y.f;
}
bool cmp2(node x,node y)
{
	return x.p<y.p;
}
int main()
{
	int n,m,l=2,r=3,p=1,i;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	cin>>a[i].v>>a[i].f,a[i].p=i;
	sort(a+1,a+m+1,cmp1);
	for(i=1;i<=m;i++)
	{
		if(a[i].f)
		{
			a[i].s=1;
			a[i].e=++p;
			continue;
		}
		if(r>p)
		{
			printf("-1\n");
			return 0;
		}
		a[i].s=l++,a[i].e=r;
		if(l==r) r++,l=2;
	}
	sort(a+1,a+m+1,cmp2);
	for(i=1;i<=m;i++)
	printf("%d %d\n",a[i].s,a[i].e);
	return 0;
}