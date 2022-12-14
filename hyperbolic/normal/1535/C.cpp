#include <stdio.h>
#include <string.h>

char x[200010];
int next0[200010],next1[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		x[a+1] = 0;
		next0[a+1] = next1[a+1] = a+1;
		
		for(int i=a;i>=1;i--)
		{
			if(x[i]=='1') next0[i] = i;
			else
			{
				if(x[i+1]=='0' || x[i+1]==0) next0[i] = i+1;
				else next0[i] = next0[i+2];
			}
		}
		for(int i=a;i>=1;i--)
		{
			if(x[i]=='0') next1[i] = i;
			else
			{
				if(x[i+1]=='1' || x[i+1]==0) next1[i] = i+1;
				else next1[i] = next1[i+2];
			}
		}
		
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			int t = next0[i]>next1[i]?next0[i]:next1[i];
			ans += (t-i);
		}
		printf("%lld\n",ans);
	}
}