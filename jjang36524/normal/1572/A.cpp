#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int>ttt[200010];
int rec[200010];
int arr[200010];
int dp[200010];
int T;
int main()
{
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		for(i=1;i<=N;i++)
			ttt[i].clear();
		for (i = 1; i <= N; i++)
		{
			int a;
			cin >> a;
			int j;
			for (j = 0; j < a; j++)
			{
				int x;
				cin >> x;
				ttt[x].push_back(i);
			}
			rec[i] = a;
			dp[i] = 0;
		}
		queue<int>t;
		for (i = 1; i <= N; i++)
			if (!rec[i])
				t.push(i);
		while (t.size())
		{
			auto a = t.front();
			t.pop();
			int j;
			for (j = 0; j < ttt[a].size(); j++)
			{
				dp[ttt[a][j]] = max(dp[ttt[a][j]], dp[a] + (a>ttt[a][j]));
				rec[ttt[a][j]]--;
				if (rec[ttt[a][j]] == 0)
				{
					t.push(ttt[a][j]);
				}
			}
		}
		int an = 0;
		for (i = 1; i <= N; i++)
		{
			if (rec[i])
			{
				cout << -1<<'\n';
				break;
			}
			else
			{
				an = max(an, dp[i]);
			}
		}
		if (i > N)
			cout << an+1<< '\n';
	}
}