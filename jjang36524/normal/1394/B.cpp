#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
int N, a, b, c, L;
using namespace std;
vector<pair<int, int>>outdeg[200100];
int d[200100][50];
int conn[50][50];
int bb[50];
int ans = 0;
void dfs(int p, int bef)
{
	int j;
	for (j = 1; j < 46; j++)
	{
		if (conn[j][bef] && bb[j])
			return;
	}
	if (p == a + 1)
	{
		ans++;
		return;
	}

	int i;
	for (i = 1; i <= p; i++)
	{
		bb[p * (p - 1) / 2 + i] = 1;
		dfs(p + 1, p * (p - 1) / 2 + i);
		bb[p * (p - 1) / 2 + i] = 0;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> b >> a;
	if (b < N)
	{
		cout << 0;
		return 0;
	}
	int i;
	for (i = 0; i < b; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		outdeg[x].push_back({ z,y });
	}
	for (i = 0; i < N; i++)
	{
		int j;
		sort(outdeg[i + 1].begin(), outdeg[i + 1].end());
		if (outdeg[i + 1].size() == 0)
		{
			cout << 0;
			return 0;
		}
		for (j = 0; j < outdeg[i + 1].size(); j++)
		{
			int nex = outdeg[i + 1][j].second;
			d[nex][(outdeg[i + 1].size()) * (outdeg[i + 1].size() - 1) / 2 + j + 1]++;
		}
	}
	for (i = 1; i <= N; i++)
	{
		int j, k;
		for (j = 1; j < 46; j++)
		{
			if (d[i][j] == 0)
				continue;
			if (d[i][j] > 1)
				conn[j][j] = 1;
			for (k = j + 1; k < 46; k++)
			{
				if (d[i][j] && d[i][k])
				{
					conn[j][k] = 1;
					conn[k][j] = 1;
				}

			}
		}
	}
	bb[1] = 1;
	dfs(2, 1);
	cout << ans;
}