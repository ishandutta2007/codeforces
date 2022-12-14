#include <bits/stdc++.h>
using namespace std;

typedef long long s64;

const int INF = 0x3f3f3f3f;

int nT, x, y, p, q;

inline s64 solve()
{
	if (p == 0 && x != 0)
		return -1;
	if (p == q && x != y)
		return -1;

	int l = 0, r = INF;
	while (l <= r)
	{
		int mid = l + r >> 1;
		s64 tx = (s64)p * mid;
		s64 ty = (s64)q * mid;
		if (tx - x >= 0 && tx - x <= ty - y)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return (s64)q * l - y;
}

int main()
{
	cin >> nT;
	while (nT--)
	{
		cin >> x >> y;
		cin >> p >> q;
		cout << solve() << endl;
	}

	return 0;
}