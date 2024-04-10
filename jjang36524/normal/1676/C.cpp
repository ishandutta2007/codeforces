#include <bits/stdc++.h>
using namespace std;
#define int long long 
string arr[55];
signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		int i;
		int mi = 797979;
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
			int j;
			
			for (j = 0; j < i; j++)
			{
				int cur = 0;
				int k;

				for (k = 0; k < M; k++)
					cur += abs(arr[i][k] - arr[j][k]);
				mi = min(mi, cur);
			}
			
		}
		cout << mi << '\n';
	}
}