#include <stdio.h>
#include <string.h>
#define MOD 998244353
char x[3010],y[3010];
int a,b,start;
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}

long long int check[3010][3010];
long long int func(int s, int t)
{
	if(t>b) return power(2,s);
	if(s==0) return 1;
	if(check[s][t]!=-1) return check[s][t];
	
	int end = (a-s)-(t-1);
	if(a-end<=b)
	{
		long long int s1=0, s2=0;
		if(x[s]==y[a-end]) s1 = func(s-1,t);
		if(x[s]==y[t]) s2 = func(s-1,t+1);
		return check[s][t] = (s1+s2)%MOD;
	}
	else
	{
		long long int s1 =0, s2=0;
		s1 = func(s-1,t);
		if(x[s]==y[t]) s2 = func(s-1,t+1);
		return check[s][t] = (s1+s2)%MOD;
	}
}

int main()
{
	scanf("%s%s",x+1,y+1);
	a = strlen(x+1), b = strlen(y+1);
	
	for(int i=a;i>=0;i--)for(int j=b;j>=0;j--) check[i][j] = -1;
	
	long long int ans = 0;
	for(int i=a;i>=b;i--)
	{
		ans += func(i,1), ans%=MOD;
	}
	printf("%lld",ans);
}