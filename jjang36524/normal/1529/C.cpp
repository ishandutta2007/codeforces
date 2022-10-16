#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int dp[100100][2];
int arr[100100][2];
vector<int>link[100100];
void dfs(int n,int p)
{
	dp[n][0] = dp[n][1] = 0;
	int i;
	for (i = 0; i < link[n].size(); i++)
	{
		if (link[n][i] == p)
			continue;
		dfs(link[n][i], n);
		dp[n][0] += max(dp[link[n][i]][0] + abs(arr[n][0] - arr[link[n][i]][0]), dp[link[n][i]][1] + abs(arr[n][0] - arr[link[n][i]][1]));
		dp[n][1] += max(dp[link[n][i]][0] + abs(arr[n][1] - arr[link[n][i]][0]), dp[link[n][i]][1] + abs(arr[n][1] - arr[link[n][i]][1]));
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		vector<int>x;
		int N;
		cin >> N;
		int i;
		for (i = 1; i <=N; i++)
		{
			cin >> arr[i][0] >> arr[i][1];
			link[i].clear();
		}
		for (i = 1; i < N; i++)
		{
			int a, b;
			cin >> a >> b;
			link[a].push_back(b);
			link[b].push_back(a);
		}
		dfs(1, 0);
		cout << max(dp[1][0], dp[1][1]) << '\n';
	}
}