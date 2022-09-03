#include<cstdio>

int a[100];
int b[100];
int d[101];

int main()
{
	int i,n,m,max=-1;
	scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]+(b[i]+99)/100<=m&&(100-b[i])%100>max)max=(100-b[i])%100;
	}
	printf("%d",max);
}