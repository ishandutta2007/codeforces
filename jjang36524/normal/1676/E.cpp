#include <bits/stdc++.h>
using namespace std;
#define int long long 
int arr[201][201];
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		int i;
		vector<int>x;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			x.push_back(a);
		}
		sort(x.begin(), x.end());
		reverse(x.begin(), x.end());
		for (i = 1; i < N; i++)
			x[i] += x[i - 1];
		for (i = 0; i < M; i++)
		{
			int c;
			cin >> c;
			int v = lower_bound(x.begin(), x.end(), c) - x.begin();
			if (v == N)
				cout << -1 << '\n';
			else
				cout << v + 1 << '\n';
		}
	}
}