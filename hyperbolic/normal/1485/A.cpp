#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int count = 0;
		int ans = 123456;
		if(b==1) count++,b++;
		for(int i=0;i<=100;i++)
		{
			int C = count+i;
			int b2 = b+i;
			int a2 = a;
			while(a2>0) C++, a2/=b2;
			ans = ans<C?ans:C;
		}
		printf("%d\n",ans);
	}
}