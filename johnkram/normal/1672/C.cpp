#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int t,n,i,j,a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",a+i);
		for(i=n;i>1;i--)if(a[i]==a[i-1])break;
		if(i==1)
		{
			puts("0");
			continue;
		}
		for(j=1;j<n;j++)if(a[j]==a[j+1])break;
		if(j+1==i)puts("0");
		else if(j+2==i)puts("1");
		else printf("%d\n",i-j-2);
	}
	return 0;
}