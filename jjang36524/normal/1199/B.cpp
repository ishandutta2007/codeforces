#include <stdio.h>
#include <math.h>
long long N, M;
int main()
{
	scanf("%lld%lld", &N, &M);
	printf("%.13lf", (double)(M*M - N * N) / (2 * N));
}