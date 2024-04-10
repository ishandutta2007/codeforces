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
		for (i = 0; i < N; i++)
		{
			int j;
			for (j = 0; j < M; j++)
				cin >> arr[i][j];
		}
		int v = 0;
		for (i = 0; i < N; i++)
		{
			int j;
			for (j = 0; j < M; j++)
			{
				int ans = 0;
				int k;
				for (k = 0; k < N; k++)
				{
					int y = i + j - k;
					if (y >= 0 && y < M)
					{
						ans += arr[k][y];
					}
					y = j-i + k;
					if (y >= 0 && y < M)
					{
						ans += arr[k][y];
					}
				}
				ans -= arr[i][j];
				v = max(v, ans);
			}
		}
		cout << v << '\n';
	}
}