#include <stdio.h>
#include <string.h>

char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d",&a);
		scanf("%s",x+1);
		b = strlen(x+1);
		int control = 0;
		for(int i=1;i<b;i++) if(x[i]!=x[i+1]) control = 1;
		if(control==0) printf("%d\n",a);
		else
		{
			int start = 1;
			for(int i=1;i<=b;i++)
			{
				if(x[i]!=x[1])
				{
					start = i;
					break;
				}
			}
			
			long long int ans = (long long int)(start-1)*(a-1);
			int count1 = 0, count2 = 0;
			for(int i=start;i<=b;i++)
			{
				if(x[i]=='R') count1++;
				else count2++;
			}
			ans += (long long int)count1*count2;
			printf("%lld\n",(long long int)a*a-ans);
		}
	}
}