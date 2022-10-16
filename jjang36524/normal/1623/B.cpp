#include <bits/stdc++.h>
using namespace std;
vector<int>pos[1010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		for (i = 1; i <= N; i++)
		{
			pos[i].clear();
		}
		for (i = 1; i <= N; i++)
		{
			int a, b;
			cin >> a >> b;
			pos[a].push_back(b);
		}
		for (i = 1; i <= N; i++)
		{
			sort(pos[i].begin(), pos[i].end());
		}
		for (i = 1; i <= N; i++)
		{
			int j;
			for (j = 0; j < pos[i].size(); j++)
			{
				if (j == 0)
				{
					cout << i << ' ' << pos[i][j] << ' ' << i << '\n';
				}
				else
				{
					cout << i << ' ' << pos[i][j] << ' ' << pos[i][j - 1] + 1 << '\n';
				}
			}
		}
	}
}