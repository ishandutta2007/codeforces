#include <iostream>
#include <algorithm>
using namespace std;
long long N, d, e;
long long arr[1000100];
long long gcd(long long x, long long y)
{
	if (!y)
		return x;
	return gcd(y, x % y);
}
int main()
{
	cin >> N;
	cin >> d;
	cin >> e;
	e *= 5;
	long long ans = 1000000000;
	long long i;
	for (i = 0; i <= N; i += d)
	{
		ans = min(ans, N-i - (N - i) / e * e);
	}
	cout << ans;
}