#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
signed main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N >> K;
		K--;
		if (N <= 62 && (1LL << (N - 1)) <= K)
		{
			cout << -1<<'\n';
		}
		else
		{
			vector<int>ar(N, 0);
			int i;
			for (i = 0; i < 60; i++)
			{
				if (K & (1LL << i))
				{
					ar[N - 2 - i] = 1;
				}
			}
			vector<int>ans;
			for (i = 0; i < N; i++)
				ans.push_back(i);
			int s = 0;
			for (i = 0; i < N; i++)
			{
				if (ar[i] == 0)
				{
					int j;
					for (j = s; j < (s + i + 1) / 2; j++)
					{
						swap(ans[j], ans[s + i - j]);
					}
					s = i+1;
				}
			}
			for (i = 0; i < N; i++)
				cout << ans[i]+1 << ' ';
			cout << "\n";
		}
	}
}