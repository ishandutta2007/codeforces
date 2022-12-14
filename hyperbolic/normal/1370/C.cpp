#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a==1) printf("FastestFinger\n");
		else if(a==2) printf("Ashishgup\n");
		else if(a%2==1) printf("Ashishgup\n");
		else
		{
			int count = 0;
			while(a%2==0) a/=2,count++;
			if(a==1) printf("FastestFinger\n");
			else
			{
				if(count>=2) printf("Ashishgup\n");
				else
				{
					for(int j=2;j*j<=a;j++)
					{
						if(a%j==0)
						{
							printf("Ashishgup\n");
							goto u;
						}
					}
					printf("FastestFinger\n");
					u:;
				}
			}
		}
	}
}