#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>links[500100];
int N, M, K,T;
int arr[5010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		vector<int>possans;
		cin >> N >> M >> K;
		K = min(K, M - 1);
		int i;
		M = N - M;
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
			if (i >= M)
			{
				possans.push_back(max(arr[i] , arr[i - M]));
			}
		}
		int tans = 0;
		for (i = 0; i <= K; i++)
		{
			int j;
			int ans = 1 << 30;
			for (j = 0; j < possans.size(); j++)
			{
				if (j < i || j >= (possans.size() - K + i))
					continue;
				ans = min(ans, possans[j]);
			}
			tans = max(tans, ans);
		}
		cout << tans << '\n';
	}
}