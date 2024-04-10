#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int gcd(int n, int m)
{
	return m ? gcd(m, n % m) : n;
}
int main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		for (i = 2; N-i-1>=2; i++)
		{
			if (gcd(i, N - i - 1) == 1)
			{
				cout << i << ' ' << N - i - 1 << ' ' << 1 << '\n';
				break;
			}
		}
	}
}