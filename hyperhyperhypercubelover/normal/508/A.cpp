#include<cstdio>

int d[1002][1002];

int main()
{
	int i,j,k,n,m,l;
	scanf("%d%d%d",&n,&m,&l);
	for(i=1;i<=l;i++)
	{
		scanf("%d%d",&j,&k);
        d[j][k]=1;
        if(d[j-1][k-1]&&d[j-1][k]&&d[j][k-1])break;
        if(d[j+1][k-1]&&d[j+1][k]&&d[j][k-1])break;
        if(d[j+1][k+1]&&d[j+1][k]&&d[j][k+1])break;
        if(d[j-1][k+1]&&d[j-1][k]&&d[j][k+1])break;
	}
	if(i<=l)printf("%d",i);
	else puts("0");
	return 0;
}