#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>X[100100];
vector<int>Y[100100];
signed main()
{
	int N, M;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int i;
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			X[a].push_back(i);
			Y[a].push_back(j);
		}
	}
	int ans = 0;
	for (i = 1; i <= 100000; i++)
	{
		sort(X[i].begin(), X[i].end());
		sort(Y[i].begin(), Y[i].end());
		int j;
		for (j = 0; j < X[i].size(); j++)
		{
			ans += (j - X[i].size() + 1 + j) * X[i][j];
			ans += (j - X[i].size() + 1 + j) * Y[i][j];
		}
	}
	cout << ans;
}