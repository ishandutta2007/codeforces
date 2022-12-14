#include <stdio.h>
#define MAX 12345678

int ans[2010];
int x[2010],y[2010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) y[i] = i-x[i];
		
		for(int i=1;i<=a;i++)
		{
			if(y[i]>=0 && (i-1)>=y[i])
			{
				ans[i] = 1;
				for(int j=1;j<=i-1;j++)
				{
					if(y[j]<=y[i] && (i-j-1)>=y[i]-y[j])
					{
						ans[i] = ans[i]>ans[j]+1?ans[i]:ans[j]+1;
					}
				}
			}
			else ans[i] = 0;
		}
		
		int S = MAX;
		for(int i=1;i<=a;i++) if(ans[i]>=b) S = S<y[i]?S:y[i];
		if(S==MAX) printf("-1\n");
		else printf("%d\n",S);
	}
}