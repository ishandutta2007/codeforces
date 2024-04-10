#include<cstdio>

int main()
{
	int i,j,n;
    scanf("%d",&n);
    if(n==2)
	{
		puts("3");
		return 0;
	}
    for(i=0;;i++)for(j=0;j<=i/2;j++)
	{
		if(n<=((i*2+1)*(i*2+1)+1)/2&&(n-j*2)/2*2%4==0)
		{
			printf("%d",i*2+1);
			return 0;
		}
	}
}