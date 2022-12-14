#include <stdio.h>

int x[100010];
int abs(int k)
{
	return k>0?k:-k;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int min = 1234567890, max = -1;
		for(int i=1;i<a;i++)
		{
			if(x[i]==-1 && x[i+1]!=-1)
			{
				max = max>x[i+1]?max:x[i+1];
				min = min<x[i+1]?min:x[i+1];
			}
		}
		for(int i=2;i<=a;i++)
		{
			if(x[i]==-1 && x[i-1]!=-1)
			{
				max = max>x[i-1]?max:x[i-1];
				min = min<x[i-1]?min:x[i-1];
			}
		}
		if(min>max) printf("0 0\n");
		else
		{
			int ans = 0;
			int k = (min+max)/2;
			for(int i=1;i<=a;i++) if(x[i]==-1) x[i] = k;
			for(int i=1;i<a;i++) ans = ans>abs(x[i]-x[i+1])?ans:abs(x[i]-x[i+1]);
			printf("%d %d\n",ans,k);
		}
	}
}