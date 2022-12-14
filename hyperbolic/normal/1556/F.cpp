#include <stdio.h>
#define MOD 1000000007

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
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

int a;
long long int check[5000010];
long long int power3[110];
int x[110];
void init(int k, int bit, long long int prob) // 2 : win, 1 : lose, 0 : other
{
	if(k>a)
	{
		//printf("%d %lld??\n",bit,prob);
		check[bit] = prob;
		return;
	}
	
	init(k+1,bit,prob);
	long long int p;
	p = 1;
	for(int i=1;i<k;i++)
	{
		if((bit/power3[i-1])%3==2)
		{
			p *= x[k], p %= MOD;
			p *= inv(x[k]+x[i]), p %= MOD;
		}
	}
	init(k+1,bit+power3[k-1],(prob*p)%MOD);
	p = 1;
	for(int i=1;i<k;i++)
	{
		if((bit/power3[i-1])%3==1)
		{
			p *= x[i], p %= MOD;
			p *= inv(x[k]+x[i]), p %= MOD;
		}
	}
	init(k+1,bit+2*power3[k-1],(prob*p)%MOD);
}

long long int check2[110][20010];
long long int func(int k, int bit)
{
	if(check2[k][bit]) return check2[k][bit];
	long long int ans = 1;
	for(int i=(bit-1)&bit;i>0;i=(i-1)&bit)
	{
		if(((i>>(k-1))&1)==0) continue;
		int sum = 0;
		int count = 0;
		for(int j=1;j<=a;j++)
		{
			if(((bit>>(j-1))&1)==1)
			{
				if(((i>>(j-1))&1)==1) sum += 2*power3[j-1];
				else sum += power3[j-1];
			}
		}
		long long int t = func(k,i)*check[sum];
		t %= MOD;
		ans += (MOD-t), ans %= MOD;
	}
	return check2[k][bit] = ans;
}

int main()
{
	power3[0] = 1;
	for(int i=1;i<=14;i++) power3[i] = (3*power3[i-1]);
	
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	init(1,0,1);
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		ans += func(i,(1<<a)-1);
		ans %= MOD;
	}
	printf("%lld",ans);
}