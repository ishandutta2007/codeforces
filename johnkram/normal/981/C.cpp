#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,i,d[MAXN],j,k;
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		d[j]++;
		d[k]++;
	}
	for(i=1,j=0;i<=n;i++)if(d[i]>2)j++;
	if(j>1)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	if(j==1)
	{
		for(k=1;k<=n;k++)if(d[k]>2)break;
		for(i=1,j=0;i<=n;i++)if(d[i]==1)j++;
		printf("%d\n",j);
		for(i=1;i<=n;i++)if(d[i]==1)printf("%d %d\n",k,i);
		return 0;
	}
	for(k=1;k<=n;k++)if(d[k]==1)break;
	for(i=k+1;i<=n;i++)if(d[i]==1)break;
	printf("1\n%d %d\n",k,i);
	return 0;
}