#include<cstdio>
#include<algorithm>

int a[1111111];

int main()
{
	long long r=0;
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		a[j]++;
	}
	j=0;
	for(i=1000000;i>0;i--)
	{
		while(a[i]+a[i+1]>=2)
		{
            if(a[i+1])a[i+1]--;
            else a[i]--;
            if(a[i+1])a[i+1]--;
            else a[i]--;
            if(j)
			{
				r+=1LL*i*j;
				j=0;
			}
            else j=i;
		}
	}
	printf("%I64d\n",r);
}