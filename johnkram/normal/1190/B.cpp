#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n,i,j,a[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)if(a[i])break;
	if(i>n)
	{
		puts("cslnb");
		return 0;
	}
	sort(a+1,a+n+1);
	for(i=1;i<n;i++)if(a[i]==a[i+1])break;
	if(i<n)
	{
		a[i]--;
		for(j=1;j<n;j++)if(a[j]==a[j+1]||a[j]<0)break;
		if(j<n)
		{
			puts("cslnb");
			return 0;
		}
		a[i]++;
	}
	for(i=1,j=0;i<=n;i++)j^=a[i]-i+1;
	if(j&1)puts("sjfnb");
	else puts("cslnb");
	return 0;
}