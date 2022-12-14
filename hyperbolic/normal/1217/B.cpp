#include <stdio.h>

int x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d%d",&x[i],&y[i]);
		int term = x[1]-y[1];
		for(int i=2;i<=a;i++) term = term>x[i]-y[i]?term:x[i]-y[i];
		int max = x[1];
		for(int i=2;i<=a;i++) max = max>x[i]?max:x[i];
		b -= max;
		if(b<=0) printf("1\n");
		else
		{
			if(term<=0) printf("-1\n");
			else
			{
				printf("%d\n",1+(b-1)/term+1);
			}
		}
	}
}