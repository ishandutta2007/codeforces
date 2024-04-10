#include <stdio.h>
#include <set>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(b==1)
		{
			if((a-1)%c==0) printf("Yes\n");
			else printf("No\n");
			continue;
		}
		
		long long int p = 1;
		while(1)
		{
			if(p>a)
			{
				printf("No\n");
				break;
			}
			if((a-p)%c==0)
			{
				printf("Yes\n");
				break;
			}
			p*=b;
		}
	}
}