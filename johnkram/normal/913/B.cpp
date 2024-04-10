#include<bits/stdc++.h>
using namespace std;
int n,i,f[1005],d[1005],a[1005];
int main()
{
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		scanf("%d",f+i);
		d[f[i]]++;
	}
	for(i=1;i<=n;i++)if(!d[i])a[f[i]]++;
	for(i=1;i<=n;i++)if(d[i]&&a[i]<3)break;
	if(i<=n)puts("No");
	else puts("Yes");
	return 0;
}