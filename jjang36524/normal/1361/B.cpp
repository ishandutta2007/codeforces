#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int N, M, T;
int arr[1000100];
int p(int n, int m)
{
	if (m == 0)
		return 1;
	if (m % 2)
		return p(n, m - 1) * n % 1000000007;
	int ans = p(n,m / 2);
	return ans * ans % 1000000007;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;

		int i;
		vector<int>t;
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			t.push_back(x);
			arr[x]++;
		}
		if (M == 1)
		{
			cout << N % 2 << '\n';
			for (i = N - 1; i >= 0; i--)
			{
				arr[t[i]] = 0;
			}
			continue;
		}
		sort(t.begin(), t.end());
		for (i = N - 1; i >= 0; i--)
		{
			if (i && t[i] == t[i - 1])
				continue;
			if (arr[t[i]] % 2)
			{
				int ans = M;
				int j = t[i] - 1;
				while (j >= 0)
				{
					if (ans <= arr[j])
					{
						arr[j] -= ans;
						ans = 0;
						break;
					}
					if (ans > N)
						break;
					ans -= arr[j];
					arr[j] = 0;
					ans *= M;
					j--;
				}
				arr[t[i]] = 0;
				if (ans)
					break;
			}
		}
		if (i == -1)
		{
			cout << 0 << '\n';
			for (i = N - 1; i >= 0; i--)
			{
				arr[t[i]] = 0;
			}
			continue;
		}
		int j;
		int ans = 0;
		for (j = 0; j <= i - 1; j++)
		{
			ans -= p(M, t[j]);
		}
		ans += p(M, t[j]);
		ans += 1000000007LL * 1000000007;
		cout << ans % 1000000007 << '\n';
		for (i = N - 1; i >= 0; i--)
		{
			arr[t[i]] = 0;
		}
	}
}