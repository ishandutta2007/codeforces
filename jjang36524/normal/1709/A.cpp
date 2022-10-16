#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int x, a[3];
		cin >>x>> a[0]>>a[1]>>a[2];
		if (a[x - 1] == 0 || a[a[x - 1] - 1] == 0)
		{
			cout << "NO";
		}
		else
			cout << "YES";
		cout << '\n';
	}
}