#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int sum = 0;
		int count = 0;
		for(int i=1;;i+=2)
		{
			if(sum+i>a)
			{
				if(sum==a) printf("%d\n",count);
				else printf("%d\n",count+1);
				break;
			}
			sum += i;
			count++;
		}

	}
}