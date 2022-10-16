#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[1000100];
int psum[1000100];
signed main()
{
	int T, N, M;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int i;
		for (i = 1; i <= M; i++)
		{
			arr[i] = 0;
			psum[i] = 0;
		}
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			arr[a] = 1;
		}
		for (i = 1; i <= M; i++)
		{
			psum[i] = psum[i - 1] + arr[i];
		}
		int ans = 1;
		for (i = 1; i <= M; i++)
		{
			if (arr[i])
				continue;
			int j;
			for (j = 1; j * i <= M; j++)
			{
				if (arr[j]&&psum[min(j*(i+1)-1,M)]-psum[j*i-1])
				{
					ans = 0;
					goto T;
				}
			}
		}
	T:
		cout << (ans ? "Yes" : "No") << '\n';
	}
}