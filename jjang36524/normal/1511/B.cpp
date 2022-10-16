#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
int prime[9];
int primes[9];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int i;
	int x = 1;
	for (i = 0; i < 9; i++)
	{
		int j;
		for (j = x;; j++)
		{
			int isp = 1;
			if (j == 1)
				isp = 0;
			int k;
			for (k = 2; k <= sqrt(j); k++)
			{
				if (j % k==0)
				{
					isp = 0;
					break;
				}
			}
			if (isp)
			{
				if (prime[i])
				{
					primes[i] = j;
					break;
				}
				
				prime[i] = j;
			}
		}
		x *= 10;
	}
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cout << prime[a - c];
		for (i = 1; i < c; i++)
			cout << '0';
		cout << ' ';
		cout << primes[b - c];
		for (i = 1; i < c; i++)
			cout << '0';
		cout << '\n';
	}
}