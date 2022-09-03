#include<cstdio>

int a[100001];

int main()
{
	int i,n;
	scanf("%d",&n);
	if(n%4==2||n%4==3)puts("-1");
	else
	{
		for(i=1;i<=n/4;i++)
		{
			a[2*i-1]=2*i;
            a[2*i]=n-2*i+2;
            a[n-2*i+2]=n-2*i+1;
            a[n-2*i+1]=2*i-1;
		}
		if(n%2)a[n/2+1]=n/2+1;
		for(i=1;i<=n;i++)printf("%d ",a[i]);
	}
}