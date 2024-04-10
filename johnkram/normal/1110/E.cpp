#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,i,a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)scanf("%d",b+i);
	if(a[1]!=b[1]||a[n]!=b[n])
	{
		puts("No");
		return 0;
	}
	for(i=1;i<n;i++)a[i]=a[i+1]-a[i];
	for(i=1;i<n;i++)b[i]=b[i+1]-b[i];
	sort(a+1,a+n);
	sort(b+1,b+n);
	for(i=1;i<n;i++)if(a[i]!=b[i])break;
	if(i==n)puts("Yes");
	else puts("No");
	return 0;
}