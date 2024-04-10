#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int a[MAXN],b[MAXN],n,i,p[MAXN],q[MAXN];
bool cmp(int x,int y)
{
	if(b[x]==b[y])return x<y;
	return b[x]>b[y];
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)scanf("%d",b+i);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++)q[p[i]]=i;
	for(i=1;i<=n;i++)printf("%d ",a[q[i]]);
	return 0;
}