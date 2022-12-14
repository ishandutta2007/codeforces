#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int b;
long long int check[210][210][210];
char x[210];
int fail[210];
long long int func(int s, int t, int k)
{
	int l = t-s;
	if(s<0) return 0;
	if(t<0) return 0;
	if(l<0) return 0;
	if(k==b) return 0;
	if(s==0&&t==0) return 1;
	if(check[s][t][k]!=-1) return check[s][t][k];
	
	long long int s1,s2;
	int p = k;
	while(1)
	{
		if(x[p+1]=='(')
		{
			s1 = func(s-1,t,p+1);
			goto u;
		}
		else if(p==0) break;
		else p = fail[p];
	}
	s1 = func(s-1,t,0);
	u:;
	
	p = k;
	while(1)
	{
		if(x[p+1]==')')
		{
			s2 = func(s,t-1,p+1);
			goto v;
		}
		else if(p==0) break;
		else p = fail[p];
	}
	s2 = func(s,t-1,0);
	v:;
	return check[s][t][k] = (s1+s2)%MOD;
}

long long int check2[210][210];
long long int comb(int s, int t)
{
	if(t==0) return 1;
	if(s==t) return 1;
	if(check2[s][t]) return check2[s][t];
	return check2[s][t] = (comb(s-1,t-1)+comb(s-1,t))%MOD;
}

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}
int main()
{
	for(int i=0;i<=200;i++) for(int j=0;j<=200;j++) for(int k=0;k<=200;k++) check[i][j][k] = check[i][j][k] = -1;
	
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	b = strlen(x+1);
	
	fail[1] = 0;
	for(int i=2;i<=b;i++)
	{
		int t = fail[i-1];
		while(t>0&&x[t+1]!=x[i]) t = fail[t];
		if(x[t+1]==x[i]) fail[i] = t+1;
		else fail[i] = 0;
	}
	long long int S = comb(2*a,a);
	S *= inv(a+1);
	S %= MOD;
	printf("%lld",(S-func(a,a,0)+MOD)%MOD);
}