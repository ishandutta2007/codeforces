#include <iostream>
#include <algorithm>
#include <math.h>
#define int long long
using namespace std;
int a(int N)
{
	long long sqr = sqrt(N);
	register long long i;
	int ans = N;
	if (N == 1)
		ans = 0;
	for (i = 2; i <= sqr; i++)
	{
		if (!(N % i))
		{
			ans /= i;
			ans *= i - 1;
		}
		while (!(N % i))
		{
			N /= i;
		}
	}
	if (N != 1)
	{
		ans /= N;
		ans *= N - 1;
	}
	return ans;
}
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
signed main()
{
	int N,M;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int i;
	int ans = 0;
	for (i = 1; i <= N; i++)
	{
		ans += a(i);
	}
	if (M > ans||M+1<N)
		cout << "Impossible";
	else
	{
		cout << "Possible" << '\n';
		int c = M;
		for (i = 1; i <= N; i++)
		{
			int j;
			for (j = i+1; j <=N; j++)
			{
				if (gcd(i, j) == 1&&c)
				{
					cout << i << ' ' << j << '\n';
					c--;
				}
				if (c == 0)
					return 0;
			}
		}
	}
}