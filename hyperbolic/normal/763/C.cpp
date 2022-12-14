#include <stdio.h>
#include <map>
std::map<long long int,int> count;
long long int x[100010];

long long int power(long long int a, long long int b,long long int MOD)
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
long long int inv(long long int k, long long int MOD)
{
	return power(k,MOD-2,MOD);
}

int check[300010];
int main()
{
	long long int a;
	int b;
	scanf("%lld%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%lld",&x[i]);
	if(b==1)
	{
		printf("%lld 0",x[1]);
		return 0;
	}
	if(a==b)
	{
		printf("0 1");
		return 0;
	}
	
	int control = 0;
	if(b > a-b)
	{
		for(int i=1;i<=b;i++) check[x[i]] = 1;
		int p = 1;
		for(int i=0;i<a;i++) if(check[i]==0) x[p++] = i;
		b = a-b;
		control = 1;
	}
	
	for(int i=1;i<=b;i++) count[(x[1]-x[i]+a)%a]++;
	for(int i=1;i<=b;i++) count[(x[2]-x[i]+a)%a]++;
	
	int C = 0;
	for(std::map<long long int,int> ::iterator it = count.begin();it!=count.end();it++) if(it->second==2) C++;
	C = b-C;
	if(C==0)
	{
		printf("-1");
		return 0;
	}
	
	long long int d = (x[1]-x[2]+a)%a;
	d *= inv(C,a), d %= a;
	count.clear();
	for(int i=1;i<=b;i++) count[x[i]]++;
	
	long long int p = x[1];
	while(1)
	{
		if(count.find(p)!=count.end())
		{
			p += (a-d);
			p %= a;
		}
		else
		{
			p += d, p %= a;
			break;
		}
	}
	
	// p,d
	for(int i=0;i<b;i++)
	{
		long long int t = p + (long long int)i*d;
		t %= a;
		if(count.find(t)==count.end())
		{
			printf("-1");
			return 0;
		}
	}
	if(control==0) printf("%lld %lld",p,d);
	else
	{
		d = (a-d), d %= a;
		p += d, p %= a;
		printf("%lld %lld",p,d);
	}
}