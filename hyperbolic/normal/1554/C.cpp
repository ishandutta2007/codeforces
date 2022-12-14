#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b) printf("0\n");
		else if(b==0) printf("1\n");
		else
		{
			int L = b+1;
			int R = 1;
			while(R<b) R*=2, R++;
			if(L>R)
			{
				printf("%d\n",R+1);
				goto u;
			}
			
			long long int ans = 0;
			for(int i=30;i>=0;i--)
			{
				int t = (1<<i);
				
				if((a&t)==0)
				{
					if((L&t)!=0)
					{
						ans += t;
					}
				}
				else
				{
					if((L&t)==0)
					{
						break;
					}
				}
			}
			
			printf("%lld\n",ans);
		}
		u:;
	}
}