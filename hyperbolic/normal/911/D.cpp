#include <stdio.h>

int x[1510];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int count = 0;
	for(int i=1;i<=a;i++) for(int j=1;j<i;j++) if(x[i]<x[j]) count++;
	count%=2;
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		int L = (d-c+1);
		count += (L*(L-1))/2;
		count %= 2;
		if(count==0) printf("even\n");
		else printf("odd\n");
	}
}