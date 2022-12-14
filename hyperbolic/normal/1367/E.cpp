#include <stdio.h>

int count[30];
char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=26;i++) count[i] = 0;
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++) count[x[i]-'a'+1]++;
		
		int ans = 0;
		for(int i=b;i>=1;i--)
		{
			if(b%i==0)
			{
				int min = 1, max = 2000;
				int L = 0;
				while(min<=max)
				{
					int h = (min+max)/2;
					int S = 0;
					for(int j=1;j<=26;j++) S += (count[j]/h);
					if(S>=i)
					{
						L = h;
						min = h+1;
					}
					else max = h-1;
				}
				//printf("%d %d!!\n",L,i);
				ans = ans>L*i?ans:L*i;
			}
		}
		printf("%d\n",ans);
	}
}