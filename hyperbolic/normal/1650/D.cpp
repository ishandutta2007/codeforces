#include <stdio.h>

int x[2010],temp[2010],ans[2010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=a;i>=1;i--)
		{
			int p = -1;
			for(int j=i;j>=1;j--) if(x[j]==i) p = j;
			ans[i] = p;
			for(int j=1;j<=i;j++) temp[(j+i-p-1)%i+1] = x[j];
			
			for(int j=1;j<=i;j++) x[j] = temp[j];
		}
		
		for(int i=1;i<=a;i++) printf("%d ",ans[i]%i);
		printf("\n");
	}
}