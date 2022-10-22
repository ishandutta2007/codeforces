#include<bits/stdc++.h>
using namespace std;
int n,i,j,a[200005];
char c[200005];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	scanf("%s",c+1);
	for(i=1;i<n;i++)if(c[i]=='1')
	{
		for(j=i+1;j<n&&c[j]=='1';j++);
		sort(a+i,a+j+1);
		i=j;
	}
	for(i=1;i<=n;i++)if(a[i]!=i)break;
	if(i>n)puts("YES");
	else puts("NO");
	return 0;
}