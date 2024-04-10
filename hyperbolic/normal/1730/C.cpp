#include <stdio.h>
#include <string.h>

char x[200010];
int count[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=9;i++) count[i] = 0;
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		for(int i=0;i<=9;i++)
		{
			int last = -1;
			for(int j=1;j<=a;j++) if(x[j]=='0'+i) last = j;
			for(int j=1;j<=last;j++)
			{
				if(x[j]==0) continue;
				
				if(x[j]=='0'+i)
				{
					count[i]++;
					x[j] = 0;
				}
				else
				{
					int val = x[j]-'0';
					count[val+1<9?val+1:9]++;
					x[j] = 0;
				}
			}
		}
		
		for(int i=0;i<=9;i++) while(count[i]--) printf("%d",i);
		printf("\n");
	}
}