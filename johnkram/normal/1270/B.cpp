#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1048576
int t,n,i,a[MAXN];
int A(int x)
{
	return x<0?-x:x;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",a+i);
		for(i=1;i<n;i++)if(A(a[i]-a[i+1])>1)break;
		if(i==n)puts("NO");
		else printf("YES\n%d %d\n",i,i+1);
	}
	return 0;
}