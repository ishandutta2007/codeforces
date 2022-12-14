#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		
		
		int ans = 12345678;
		int L=1, R=1;
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				if((c-b)%((j-i))==0)
				{
					int t = (c-b)/(j-i);
					int max = c+(a-j)*t;
					int min = b-(i-1)*t;
					if(min>=1&&ans>max)
					{
						ans = max;
						L = i;
						R = j;
					}
				}
			}
		}
		
		int t = (c-b)/(R-L);
		int max = c+(a-R)*t;
		int min = b-(L-1)*t;
		for(int i=1;i<=a;i++) printf("%d ",min+(i-1)*t);
		printf("\n");
	}
}