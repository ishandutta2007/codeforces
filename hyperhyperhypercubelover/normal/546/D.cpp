#include<cstdio>

int a[5555555];

int main()
{
	int i,j,k,n;
	for(i=2;i<=5000000;i++)
	{
		if(!a[i])for(j=1;i*j<=5000000;j++)for(k=i*j;k%i==0;k/=i)a[i*j]++;
		a[i]+=a[i-1];
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		printf("%d\n",a[j]-a[k]);
	}
}