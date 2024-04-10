#include <stdio.h>
#define MAX (long long int)1e16

int x[100010],y[100010],z[100010];
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
		for(int i=1;i<=a;i++) scanf("%d",&z[i]);
		
		
		long long int ans = 0;
		long long int S = -MAX;
		for(int i=2;i<=a;i++)
		{
			if(y[i]==z[i])
			{
				S = 0;
				ans = ans>S+2+x[i]-1?ans:S+2+x[i]-1;
			}
			else if(y[i]<z[i])
			{
				S = S+2+(x[i-1]-z[i])+(y[i]-1)>z[i]-y[i]?S+2+(x[i-1]-z[i])+(y[i]-1):z[i]-y[i];
				ans = ans>S+2+x[i]-1?ans:S+2+x[i]-1;
			}
			else
			{
				S = S+2+(x[i-1]-y[i])+(z[i]-1)>y[i]-z[i]?S+2+(x[i-1]-y[i])+(z[i]-1):y[i]-z[i];
				ans = ans>S+2+x[i]-1?ans:S+2+x[i]-1;
			}
			//printf("%d %lld!!\n",i,ans);
		}
		printf("%lld\n",ans);
	}
}