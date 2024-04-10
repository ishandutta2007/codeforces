#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a==0)
		{
			printf("1 1\n");
			continue;
		}
		
		for(int i=1;i*i<a;i++)
		{
			if(a%i==0)
			{
				int s = i;
				int t = a/i;
				if(s==t) continue;
				if(t>s)
				{
					int temp = t;
					t = s;
					s = temp;
				}
				if((s+t)%2==1) continue;
				
				int n = (s+t)/2;
				int k = (s-t)/2;
				int m = (n/k);
				if(n<(k+1)*m)
				{
					printf("%d %d\n",n,m);
					goto u;
				}
			}
		}
		printf("-1\n");
		u:;
	}
}