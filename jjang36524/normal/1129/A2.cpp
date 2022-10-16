#include <iostream>
int N, M;
#include <vector>
#include <algorithm>
using namespace std;
vector<int>candieswaiting[5001];
int maxpos[5001];
int main()
{
	cin >> N >> M;
	int i;
	for (i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		candieswaiting[a].push_back((b-a+N)%N);
	}
	for (i = 1; i <= N; i++)
	{
		int j;
		for (j = 0; j < candieswaiting[i].size();j++)
		{
			maxpos[i] = max(candieswaiting[i][j],maxpos[i]);
		}
		sort(candieswaiting[i].begin(), candieswaiting[i].end());
	}
	for (i = 1; i <= N; i++)
	{
		int j;
		int ans=0;
		for (j = 1; j <=N; j++)
		{
			if (!candieswaiting[j].size())
				continue;
			ans =max((unsigned int)ans, (candieswaiting[j].size() - 1)*N + (j - i + N) % N + candieswaiting[j][0]);
		}
		cout << ans << ' ';
	}
}