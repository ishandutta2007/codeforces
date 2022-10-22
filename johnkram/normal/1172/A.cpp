#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
int n,a[MAXN],a1[MAXN],b[MAXN],i,j,l,r,mid;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=2*n;i++)scanf("%d",a+i);
	for(i=1;i<=2*n;i++)b[a[i]]=i;
	for(i=2*n;a[i]>1;i--)if(a[i]!=a[i-1]+1)break;
	for(j=a[2*n]+1;j<=n;j++)if(b[j]>=n+j-a[2*n])break;
	if(j>n&&a[i]<2)
	{
		printf("%d\n",n-a[2*n]);
		return 0;
	}
	l=0;
	for(i=1,j=0;i<=n;i++)if(!a[i])j++;
	for(;i<=2*n;i++)if(a[i])
	{
		j--;
		if(!j)break;
	}
	r=i-n;
	while(l+1<r)
	{
		mid=l+r>>1;
		for(i=1;i<=2*n;i++)a1[i]=a[i];
		for(i=1,j=n+mid;i<j;i++)while(a1[i])
		{
			swap(a1[i],a1[j]);
			j--;
		}
		for(i=1;i<=2*n;i++)b[a1[i]]=(i-mid+2*n-1)%(2*n)+1;
		for(i=1;i<=n;i++)if(b[i]>=n+i)break;
		if(i>n)r=mid;
		else l=mid;
	}
	printf("%d\n",r+n);
	return 0;
}