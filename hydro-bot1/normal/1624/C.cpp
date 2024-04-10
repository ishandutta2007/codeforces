// Hydro submission #61e16bfc07e2d89b5f6232f0@1642163197028
#include <bits/stdc++.h>
using namespace std;
int h[100];

int main()
{
	bool flag;
	int t, n, i, x;
	cin >> t;
	while (t--)
	{
		cin >> n;
		flag = true;
		for (i = 1; i <= n; i++)
			h[i] = 0;
		for (i = 1; i <= n; i++)
		{
			cin >> x;
			while (1)
			{
				if (x <= n && h[x] == 0)
				{
					h[x] = 1;
					break;
				}
				x = x / 2;
				if (x == 0)
					break;
			}
		}
		for (i = 1; i <= n; i++)
			if (h[i] == 0)
			{
				flag = false;
				break;
			}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		//	for (i = 1; i <= n; i++)
		//		cout << h[i];
	}
	return 0;
}