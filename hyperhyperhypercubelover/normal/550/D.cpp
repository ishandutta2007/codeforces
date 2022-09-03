#include<cstdio>

int a[111];

int main()
{
	int i,j,n;
	scanf("%d",&n);
	if(n%2==0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	if(n==1)
	{
		puts("2 1");
		puts("1 2");
		return 0;
	}
    printf("%d %d\n",(n+2)*2,(n+2)*n);
    printf("1 %d\n",n+3);
	for(i=1;i<=n+2;i++)for(j=1;j<=n;j++)if((i%2==0||j!=1)&&(i+j-1)%(n+2)+1>i)printf("%d %d\n%d %d\n",i,(i+j-1)%(n+2)+1,i+n+2,(i+j-1)%(n+2)+n+3);
}