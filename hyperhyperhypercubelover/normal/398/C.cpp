#include<cstdio>

int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    if(n==5)
	{
        printf("1 3 1\n1 5 1\n2 4 1\n4 5 3\n1 2\n2 3\n");
        return 0;
	}
    if(n&1)printf("%d %d %d\n",n-1,n,1);
    for(i=1;i<=n/2;i++)printf("%d %d %d\n",i,i+n/2,1);
    for(i=1;i<n/2;i++)printf("%d %d %d\n",i+n/2,i+n/2+1,i*2-1);
    for(i=1;i<n/2;i++)printf("%d %d\n",i,i+1);
	printf("1 3\n");
}