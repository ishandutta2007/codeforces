#include <stdio.h>
#define MOD 1000000007

int x[510][510];
long long int check[510][510][3];

long long int func(int s, int t, int type)
{
	if(t<=s+1) return 1;
	if(check[s][t][type]!=-1) return check[s][t][type];
	
	long long int ans = 0;
	if(type==0)
	{
		for(int i=s+1;i<=t-1;i++)
		{
			if(x[s][i]==1)
			{
				ans += func(s,i,0)*func(i,t,0);
				ans %= MOD;
			}
		}
		for(int i=s+1;i<=t-1;i++)
		{
			if(x[i][t]==1)
			{
				ans += func(s,i,1)*func(i,t,0);
				ans %= MOD;
			}
		}
	}
	else
	{
		for(int i=s+1;i<=t-1;i++)
		{
			if(x[i][t]==1)
			{
				ans += func(s,i,1)*func(i,t,0);
				ans %= MOD;
			}
		}
	}
	
	return check[s][t][type] = ans;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a+1;i++) for(int j=1;j<=a+1;j++) check[i][j][0] = check[i][j][1] = -1;
	
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
	
	for(int i=1;i<=a;i++) x[i][a+1] = x[i][1];
	for(int j=1;j<=a;j++) x[a+1][j] = x[1][j];
	x[a+1][a+1] = 0;
	
	long long int ans = 0;
	for(int i=2;i<=a;i++)
	{
		if(x[1][i]==1)
		{
			ans += func(1,i,1) * func(i,a+1,0);
			ans %= MOD;
		}
	}
	printf("%lld",ans);
}