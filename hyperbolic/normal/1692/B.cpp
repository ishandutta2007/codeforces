#include <stdio.h>

int x[110],count[10010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=10000;i++) count[i] = 0;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) count[x[i]]++;
		int C = 0;
		for(int i=1;i<=10000;i++) if(count[i]>0) C += (count[i]-1);
		printf("%d\n",a-((C+1)/2)*2);
	}
}