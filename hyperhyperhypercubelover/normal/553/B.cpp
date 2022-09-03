#include<cstdio>

long long a[55],b[55];

int main()
{
	long long m;
	int i,j,n;
	scanf("%d%I64d",&n,&m);
    a[1]=1;
    for(i=2;i<=n;i++)
	{
		a[i]=a[i-1]+b[i-1];
		b[i]=a[i-1];
	}
	j=0;
	for(i=n;i;i--)
	{
		if(a[i]<m)
		{
            j=-1;
            m-=a[i];
		}
		printf("%d ",n-i-j+1);
		if(j==1)j=0;
		if(j==-1)j=1;
	}
}