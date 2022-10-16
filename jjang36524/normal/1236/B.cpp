#include <iostream>
using namespace std;
long long N, M;
#define mod 1000000007
long long sqa(long long n, long long num)
{
	if (n == 0)
		return 1;
	if (n % 2)
	{
		return (sqa(n - 1, num) * num) % mod;
	}
	long long ret = sqa(n / 2, num);
	return (ret * ret) % mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	long long res = (sqa(M, 2) + mod - 1) % mod;
	cout << sqa(N, res);
}