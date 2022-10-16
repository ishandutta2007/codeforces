#include <stdio.h>
#include <math.h>
long long N;
long long a[400100];
int b;
long long gcd(long long a, long long b)
{
	if (!b)return a;
	return gcd(b, a%b);
}
long long gc;
int main()
{
	scanf("%lld", &N);
	long long i;
	for (i = 0; i < N; i++)
	{
		scanf("%lld", a + i);
		if (!i)
		{
			gc = a[i];
		}
		else
		{
			gc = gcd(gc, a[i]);
		}
	}
	long long s = sqrt(gc);
	for (i = 1; i <= s; i++)
	{
		if(!(gc%i))
		{ 
			b+=2;
		}
		if (i*i == gc)
			b--;
	}
	printf("%d", b);
}