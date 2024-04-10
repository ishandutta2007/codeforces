#include <stdio.h>

int check[110010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		for(int j=c;j<=d;j++) check[j] = 1;
	}
	int ans = 0;
	for(int i=1;i<=b;i++) ans += (1-check[i]);
	printf("%d\n",ans);
	for(int i=1;i<=b;i++) if(check[i]==0) printf("%d ",i);
}