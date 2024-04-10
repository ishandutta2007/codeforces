#include<cstdio>

int a[111];
int r[111],rn;

int main()
{
    int i,j,n,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)
	{
		scanf("%d",&t);
		if(t==1||t==3)a[i]=1;
	}
	for(i=1;i<=n;i++)if(!a[i])r[rn++]=i;
	printf("%d\n",rn);
	for(i=0;i<rn;i++)printf("%d ",r[i]);
}