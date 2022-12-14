#include <stdio.h>
#include <map>

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	for(int i=1;i<=b;i++) ans*=a;
	return ans;
}

int func(int k)
{
	int ans = 0;
	while(k)
	{
		ans += k%10;
		k/=10;
	}
	return ans;
}
std::map<long long int,int> M;

void print(long long int k)
{
	while(k>=9)
	{
		printf("9");
		k-=9;
	}
	printf("%d",k);
}
int main()
{
	long long int a;
	scanf("%lld",&a);
	
	long long int S = 4500;
	for(int i=1;i<100;i++)
	{
		long long int T = 0;
		for(int j=1;j<=10;j++)
		{
			T+=S;
			T%=a;
		}
		S = T;
	}

	long long int b = a-S;
	
	printf("%lld ",b);
	printf("1");
	printf("%0100lld ",b-1);
}