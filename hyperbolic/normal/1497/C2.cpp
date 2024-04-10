#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=b-3;i++) printf("1 ");
		a -= (b-3);
		
		int C = 1;
		while(1)
		{
			if(a==3)
			{
				printf("%d %d %d\n",C,C,C);
				break;
			}
			else if(a==4)
			{
				printf("%d %d %d\n",C,C,2*C);
				break;
			}
			else if(a%2==1)
			{
				printf("%d %d %d\n",C,((a-1)/2)*C,((a-1)/2)*C);
				break;
			}
			else C*=2, a/=2;
		}
	}
}