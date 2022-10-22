#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,m,i,a[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)a[i]=i;
	for(i=m=1;i<=n;i++)if(i+(n+i-1)/i<m+(n+m-1)/m)m=i;
	for(i=1;(i-1)*m<n;i++)reverse(a+(i-1)*m+1,a+min(i*m,n)+1);
	for(i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}