#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#define int long long
using namespace std;
int N,M,T;
int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int gc = gcd(N , M);
		N /= gc;
		M /= gc;
		int i;
		int sq = sqrt(M);
		int ans = M;
		for (i = 2; i <= sq; i++)
		{
			if (M % i == 0)
			{
				ans /= i;
				ans *= (i - 1);
				while (M % i == 0)
					M /= i;
			}
		}
		if (M > 1)
		{
			ans /= M;
			ans *= (M - 1);
		}
		cout << ans << '\n';
	}
}