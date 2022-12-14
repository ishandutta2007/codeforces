#include <stdio.h>
#include <algorithm>

int x[500010],y[100010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		std::sort(x+1,x+a+1);
		std::sort(y+1,y+a+1);
		
		int b = a/4;
		int s1 = 0, s2 = 0;
		for(int i=b+1;i<=a;i++) s1 += x[i];
		for(int i=b+1;i<=a;i++) s2 += y[i];
		if(s1>=s2) printf("0\n");
		else
		{
			for(int i=a+1;i<=5*a;i++) x[i] = 100;
			
			int p = 1;
			int q = 0;
			for(int i=a+1;;i++)
			{
				s1 += 100;
				if(i%4==0)
				{
					s1 -= x[b+p];
					p++;
				}
				else if(b-q>=1) s2 += y[b-q], q++;
				
				if(s1>=s2)
				{
					printf("%d\n",i-a);
					break;
				}
			}
		}
	}
}