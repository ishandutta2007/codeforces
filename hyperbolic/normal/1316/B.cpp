#include <stdio.h>


char x[5010],y[5010];
char ans[5010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d%s",&a,x+1);
		int ans2 = 1;
		for(int i=1;i<=a;i++) ans[i] = x[i];
		
		for(int i=2;i<=a;i++)
		{
			for(int j=i;j<=a;j++) y[j-i+1] = x[j];
			if((a+i)%2==0) for(int j=1;j<i;j++) y[a-i+1+j] = x[i-j];
			else for(int j=1;j<i;j++) y[a-i+1+j] = x[j];
			
			
			for(int j=1;j<=a;j++)
			{
				if(ans[j]<y[j]) break;
				if(ans[j]>y[j])
				{
					for(int k=1;k<=a;k++) ans[k] = y[k];
					ans2 = i;
					break;
				}
			}
		}
		for(int i=1;i<=a;i++) printf("%c",ans[i]);
		printf("\n%d\n",ans2);
	}
}