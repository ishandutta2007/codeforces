#include<bits/stdc++.h>
using namespace std;
int n,i,a[100],p[100],q[100];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++)q[p[i]]=i;
	for(i=1;i<=n;i++)printf("%d ",a[p[q[i]%n+1]]);
	return 0;
}