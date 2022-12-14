#include <stdio.h>
#define MOD 1000000007

long long int pow(long long int s, long long int t)
{
	long long int ans = 1;
	while(t)
	{
		if(t%2==1) ans*=s,ans%=MOD;
		s*=s,s%=MOD;
		t/=2;
	}
	return ans;
}

long long int check[1000110][21];
long long int func(int s, int t)
{
	if(s==t) return 1;
	if(t==0) return 1;
	if(check[s][t]) return check[s][t];
	return check[s][t] = (func(s-1,t-1)+func(s-1,t))%MOD;
}

int main()
{
	int query;
	scanf("%d",&query);
	while(query--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		long long int ans = 1;
		int k = a;
		for(int i=2;i*i<=a;i++)
		{
			int count = 0;
			while(k%i==0)
			{
				count++;
				k/=i;
			}
			ans *= func(count+b-1,count);
			ans%=MOD;
		}
		if(k!=1) ans *= func(b,1);
		ans%=MOD;
		printf("%lld\n",(ans*pow(2,b-1)%MOD));
	}
}