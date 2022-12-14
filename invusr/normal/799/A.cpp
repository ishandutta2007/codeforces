#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t, k, d;
	cin >> n >> t;
	cin >> k >> d;

	int p = (n - 1) / k + 1;
	int u = p * t;

	int l = d, r = 23333333;
	while (l <= r)
	{
		int mid = l + r >> 1;
		int p1 = mid / t;
		int p2 = (mid - d) / t;
		if (p1 + p2 >= p)
			r = mid - 1;
		else
			l = mid + 1;
	}

	puts(l >= u ? "NO" : "YES");

	return 0;
}