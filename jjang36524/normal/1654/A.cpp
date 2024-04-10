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
		vector<int>x;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			x.push_back(a);
		}
		sort(x.begin(), x.end());
		cout << x[N - 2] + x[N - 1] << '\n';
	}
}