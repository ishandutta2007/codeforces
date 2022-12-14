#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int m1 = 0, m2 = 0, M1 = 0, M2 = 0;
		for(int i=1;i<=a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			if(b==0)
			{
				m2 = m2<c?m2:c;
				M2 = M2>c?M2:c;
			}
			else
			{
				m1 = m1<b?m1:b;
				M1 = M1>b?M1:b;
			}
		}
		printf("%d\n",2*(M1+M2-m1-m2));
	}
}