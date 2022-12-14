#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		long long int s1 = 0, s2 = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(b<0) s2 += b;
			else s1 += b;
		}
		if(s1+s2>=0) printf("%lld\n",s1+s2);
		else printf("%lld\n",-(s1+s2));
	}
}