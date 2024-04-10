#include <stdio.h>
#define MAX (long long int)1e18 + 1

int ans[100010];
long long int DP[100010],S[100010];

int main()
{
	DP[0] = 0;
	S[0] = 0;
	for(int i=1;i<=100000;i++)
	{
		DP[i] = S[i-1]+1;
		S[i] = S[i-1] + DP[i];
		if(DP[i]>MAX) DP[i] = MAX;
		if(S[i]>MAX) S[i] = MAX;
	}
	DP[0] = 1;
	
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		long long int b;
		scanf("%d%lld",&a,&b);
		
		int p = 1;
		while(p<=a)
		{
			for(int i=p;i<=a;i++)
			{
				if(DP[a-i]>=b)
				{
					for(int j=p;p+i-j>=p;j++) ans[j] = (p+i-j);
					p = i+1;
					goto u;
				}
				else b -= DP[a-i];
			}
			
			printf("-1\n");
			goto v;
			u:;
		}
		
		if(b==1)
		{
			for(int i=1;i<=a;i++) printf("%d ",ans[i]);
			printf("\n");
		}
		else printf("-1\n");
		v:;
	}
}