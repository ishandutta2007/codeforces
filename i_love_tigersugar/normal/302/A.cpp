#include<stdio.h>
int m,n;
int pl,mi;
int tmp,min;
int i,l,r;
int main(void)
{
	scanf("%d",&n);
	scanf("%d",&m);
	pl=0; mi=0;
	for (i=1;i<=n;i=i+1)
		{
			scanf("%d",&tmp);
			if (tmp>0) pl++; else mi++;
		}
	if (pl>mi) min=mi; else min=pl;	
	for (i=1;i<=m;i=i+1)
		{
			scanf("%d",&l);
			scanf("%d",&r);
			if ((r-l+1)%2==1)
				{
					printf("0\n");
					continue;
				}
			if ((r-l+1)/2<=min) printf("1\n"); else printf("0\n");							
		}
}