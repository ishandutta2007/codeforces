#include <stdio.h>
#include <algorithm>
long long N, K;
long long arr[200100];
int main()
{
	scanf("%lld%lld", &N, &K);
	long long i;
	for (i = 0; i < N; i++)
	{
		scanf("%lld",&arr[i]);
	}
	std::sort(arr, arr + N);
	long long med = (N - 1) / 2;
	long long s = 0;
	for (i = med; i < N; i++)
	{
		if (i != med && (s + K) / (i - med) < arr[i])
		{
			printf("%lld", (s + K) / (i - med));
			return 0;
		}
		s += arr[i];
		
	}
	printf("%lld", (s + K) / ((N + 1) / 2));
}