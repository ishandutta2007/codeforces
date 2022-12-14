#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		long long int s1 = 0, s2 = 0;
		int count1 = 0 ,count2 = 0;
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			if(c%2==1) s1+=c,count1++;
			else s2+=c,count2++;
		}
		while(b--)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			if(c==0)
			{
				s2 += count2*d;
				if(d%2==1)
				{
					s1 += s2;
					count1 += count2;
					s2 = 0, count2 = 0;
				}
			}
			else
			{
				s1 += count1*d;
				if(d%2==1)
				{
					s2 += s1;
					count2 += count1;
					s1 = 0, count1 = 0;
				}
			}
			printf("%lld\n",s1+s2);
		}
	}
}