#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a>c || b>c)
		{
			printf("0\n");
			continue;
		}
		int d = a, e = b;
		int ans1 = 0, ans2 = 0;
		for(int i=0;;)
		{
			if(d>c || e>c)
			{
				ans1 = i;
				break;
			}
			d += e;
			i++;
			
			if(d>c || e>c)
			{
				ans1 = i;
				break;
			}
			e += d;
			i++;
		}
		
		d = a, e = b;
		for(int i=0;;)
		{
			if(d>c || e>c)
			{
				ans2 = i;
				break;
			}
			e += d;
			i++;
			
			if(d>c || e>c)
			{
				ans2 = i;
				break;
			}
			d += e;
			i++;
		}
		
		int ans3 = (c-a)/b+1;
		int ans4 = (c-b)/a+1;
		int M = ans1;
		M = M<ans2?M:ans2;
		M = M<ans3?M:ans3;
		M = M<ans4?M:ans4;
		printf("%d\n",M);
	}
}