#include <stdio.h>
#include <string.h>
#define MOD 1000000007
char x[1000010];
int fail[1000010];
int check[1000010];
long long int power(long long int s, long long int t)
{
	long long int ans = 1;
	long long int k = s;
	while(t)
	{
		if(t%2==1) ans*=k, ans%=MOD;
		t/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	int l = strlen(x+1);
	fail[1] = 0;
	for(int i=2;i<=l;i++)
	{
		int t = fail[i-1];
		while(t>0)
		{
			if(x[t+1]==x[i])
			{
				fail[i] = t+1;
				goto u;
			}
			else t = fail[t];
		}
		if(x[1]==x[i]) fail[i] = 1;
		else fail[i] = 0;
		u:;
	}
	int k = l;
	while(k>=1)
	{
		check[l-k+1] = 1;
		k = fail[k];
	}
	
	int last = 0;
	long long int ans = 1;
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		if(last<c)
		{
			ans *= power(26,c-last-1);
			ans%=MOD;
			last = c+l-1;
		}
		else
		{
			if(check[l-(last-c)]==1) last = c+l-1;
			else
			{
				printf("0");
				return 0;
			}
		}
	}
	ans *= power(26,a-last);
	ans%=MOD;
	printf("%lld",ans);
}