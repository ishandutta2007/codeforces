#include <stdio.h>

int x[300010];
int main()
{
	for(int i=1;i<=300000;i++) x[i] = (i^x[i-1]);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int t = x[a-1];
		if(b==t) printf("%d\n",a);
		else if((b^t)==a) printf("%d\n",a+2);
		else printf("%d\n",a+1);
	}
}