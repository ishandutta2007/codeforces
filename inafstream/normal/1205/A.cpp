#include <bits/stdc++.h>
using namespace std;
int n,m,i,j;
int main()
{
	cin>>n;
	if (n%2==0)
	{
		puts("NO");
		return 0;
	}
	
	puts("YES");
	int l=1,r=n+n;
	for (i=1;i<=n/2;i++)
	{
		printf("%d ",l);l+=2;
		printf("%d ",r);r-=2;
	}
	l=2;r=n+n-1;
	printf("%d ",n);
	for (i=1;i<=n/2;i++)
	{
		printf("%d ",l);l+=2;
		printf("%d ",r);r-=2;
	}
	printf("%d ",n+1);
	
	
	return 0;
}