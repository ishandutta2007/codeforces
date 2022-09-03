#include<cstdio>

int r[999];

int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for(i=0;n;i++)
	{
		for(j=1;j<=n;j*=10);
		k=0;
		while(j/=10)
		{
			if(n/j%10)k+=j;
		}
		r[i]=k;
        n-=k;
	}
	printf("%d\n",i);
	while(i--)printf("%d ",r[i]);
}