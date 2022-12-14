#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			if(i*(i+1)/2>=a)
			{
				if(i*(i+1)/2==a+1) printf("%d\n",i+1);
				else printf("%d\n",i);
				break;
			}
		}
	}
}