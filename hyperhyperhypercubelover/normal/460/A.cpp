#include<cstdio>

int main()
{
	int i,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;n;i++)
	{
		n--;
		if(i%m==m-1)n++;
	}
	printf("%d",i);
}