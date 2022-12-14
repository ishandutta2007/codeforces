#include <stdio.h>
#include <string.h>

char x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int S = 0;
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i<=a;i++) S += (strlen(x[i]+1)%2);
		
		if(S%2==1) printf("%d\n",a);
		else
		{
			if(S>=2) printf("%d\n",a);
			else
			{
				int S1 = 0, S2 = 0;
				for(int i=1;i<=a;i++)
				{
					int b = strlen(x[i]+1);
					for(int j=1;j<=b;j++)
					{
						if(x[i][j]=='1') S1++;
						else S2++;
					}
				}
				if(S1%2==1) printf("%d\n",a-1);
				else printf("%d\n",a);
			}
		}
	}
}