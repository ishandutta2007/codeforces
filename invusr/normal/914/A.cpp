#include <bits/stdc++.h>
using namespace std;

int n, x;
int res = -233333333;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;

		if (x < 0)
		{
			res = max(res, x);
			continue;
		}

		int l = sqrt(x);
		while (l * l < x)
			++l;
		while (l * l > x)
			--l;

		if (l * l != x)
			res = max(res, x);
	}

	cout << res << endl;

	return 0;
}