#include <stdio.h>
#define MOD 1000000007

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int s = a;
	while(b)
	{
		if(b%2==1) ans*=s, ans%=MOD;
		b/=2;
		s*=s, s%=MOD;
	}
	
	return ans;
}

int count[5][200010];
int func(int k, int L, int R)
{
	return count[k][R]-count[k][L-1];
}

char x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) if(x[i]=='a') count[1][i] = 1;
	for(int i=1;i<=a;i++) if(x[i]=='c') count[2][i] = 1;
	for(int i=1;i<=a;i++) if(x[i]=='?') count[3][i] = 1;
	for(int j=1;j<=3;j++) for(int i=1;i<=a;i++) count[j][i] += count[j][i-1];
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='?'||x[i]=='b')
		{
			int a1 = func(1,1,i-1);
			int a2 = func(3,1,i-1);
			int b1 = func(2,i+1,a);
			int b2 = func(3,i+1,a);
			long long int s1 = (a1*power(3,a2)+a2*power(3,a2-1))%MOD;
			long long int s2 = (b1*power(3,b2)+b2*power(3,b2-1))%MOD;
			ans += (s1*s2)%MOD;
			ans %= MOD;
		}
	}
	printf("%lld",ans);
}