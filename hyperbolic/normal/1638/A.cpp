#include <stdio.h>

int x[510],y[510];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int start = a+1;
		for(int i=1;i<=a;i++)
		{
			if(x[i]!=i)
			{
				start = i;
				break;
			}
		}
		
		int t = a+1;
		for(int i=start+1;i<=a;i++)
		{
			if(x[i]==start)
			{
				t = i;
			}
		}
		
		for(int i=start;i<=t;i++) y[i] = x[start+t-i];
		for(int i=start;i<=t;i++) x[i] = y[i];
		
		for(int i=1;i<=a;i++) printf("%d ",x[i]);
		printf("\n");
	}
}