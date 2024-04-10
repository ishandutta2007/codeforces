#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		if (M == 1)
		{
			cout << "YES" << '\n';
			int i;
			for (i = 0; i < N; i++)
			{
				cout << i + 1 << '\n';
			}
		}
		else if (N % 2)
		{
			cout << "NO" << '\n';
		}
		else
		{
			cout << "YES" << '\n';
			int i;
			for (i = 0; i < N; i++)
			{
				int j;
				for (j = 0; j < M; j++)
				{
					cout << (i / 2*2) * M + j*2 + 1 + (i % 2) << ' ';
				}
				cout << '\n';
			}
		}
	}
}