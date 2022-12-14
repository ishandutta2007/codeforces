#include <stdio.h>

int ans[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) ans[i] = 0;
		
		int c = 0;
		for(int i=2;i+1<=a;i+=2) c++;
		if(b>c) printf("-1\n");
		else
		{
			int p = 0;
			for(int i=2;i+1<=a;i+=2)
			{
				if(p>=b) break;
				ans[i] = a-p;
				p++;
			}
			
			p = 1;
			for(int i=1;i<=a;i++)
			{
				if(ans[i]==0) ans[i] = p++;
			}
			
			for(int i=1;i<=a;i++) printf("%d ",ans[i]);
			printf("\n");
		}
	}
}