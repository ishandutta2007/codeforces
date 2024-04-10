#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		int s = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			s += (a <= 2048) * a;
		}
		cout << (s < 2048 ? "NO" : "YES") << '\n';
	}
}