#include <stdio.h>

int x[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	if(a%2==0)
	{
		if(x[b]%2==1) printf("odd");
		else printf("even");
	}
	else
	{
		int s = 0;
		for(int i=1;i<=b;i++) s += (x[i]%2);
		
		if(s%2==0) printf("even");
		else printf("odd");
	}
}