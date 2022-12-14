#include <bits/stdc++.h>
using namespace std;

inline int solve(int n)
{
	for (int i = 1000000000; i; i /= 10)
		if (n >= i)
		{
			int k = n / i + 1;
			int r = i * k - n;
			return r;
		}
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;

	return 0;
}