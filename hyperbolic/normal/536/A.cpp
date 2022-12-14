#include <stdio.h>

long long int MAX = 1;
int main()
{
	for(int i=1;i<=14;i++) MAX*=10;
	
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		long long int min = d, max = 1234567;
		long long int ans = -1;
		while(min<=max)
		{
			long long int h = (min+max)/2;
			long long int S1 = ((a*(h-d+1)+(h+d-2)*(h-d+1)*b/2)-1)/f+1;
			long long int S2 = S1>a+(h-1)*b?S1:a+(h-1)*b;
			if(S2<=e)
			{
				ans = h;
				min = h+1;
			}
			else max = h-1;
		}
		printf("%lld\n",ans);
	}
}