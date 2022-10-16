#include <iostream>
using namespace std;
long long N, M, Q;
long long a, b, c, d;
long long G;
long long gcd(long long a, long long b)
{
	if (!b)
		return a;
	return gcd(b, a%b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> Q;
	G = gcd(N, M);
	while (Q--)
	{
		cin >> a >> b >> c >> d;
		long long aans;
		if (a == 1)
		{
			aans = (b-1) / (N / G);
		}
		else
		{
			aans = (b-1) / (M / G);
		}
		long long cans;
		if (c == 1)
		{
			cans = (d - 1) / (N / G);
		}
		else
		{
			cans = (d - 1) / (M / G);
		}

		if (aans != cans)
		{
			cout << "NO" << '\n';
		}
		else
		{
			cout << "YES" << '\n';
		}
	}
}