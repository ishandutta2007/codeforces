#include<cstdio>

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)if(i*9+(i<n)>=m)break;
    if(n==1&&m==0)printf("0 0");
    else if(n>1&&m==0)printf("-1 -1");
    else if(i>n)puts("-1 -1");
    else
	{
		printf("%d",i<n?1:m-(i-1)*9);
        for(j=n-1;j>i;j--)printf("0");
        if(i<n)printf("%d",m-(i-1)*9-1);
        for(j=1;j<i;j++)printf("9");

        printf(" ");

        for(i=n;i>=1;i--)if(i*9<=m)break;
        for(j=0;j<i;j++)printf("9");
        if(i<n)printf("%d",m-i*9);
        for(j=i+1;j<n;j++)printf("0");
	}
}