#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[501][501];
int ans1[1001];
vector<pair<int, int>>ans2;
int c;

void dfs(vector<int>x,int p)
{
	
	if (x.size() == 1)
	{
		ans1[x[0]] = arr[x[0]][x[0]];
		ans2.push_back({ x[0],p });
		return;
	}
	else
	{
		vector<int>cou[501];
		c++;
		int curc = c;
		if (p)
			ans2.push_back({ c,p });
		int i, j;
		int man = 0;
		for (i = 0; i < x.size(); i++)
		{
			for (j = 0; j < x.size(); j++)
			{
				man = max(man, arr[x[i]][x[j]]);
			}
		}
		ans1[c] = man;
		int cc = 0;
		for (i = 0; i < x.size(); i++)
		{
			for (j = 0; j < cc; j++)
			{
				if (arr[cou[j][0]][x[i]] != man)
					break;
			}
			cou[j].push_back(x[i]);
			if (j == cc)
				cc++;
		}
		for (i = 0; i < cc; i++)
		{
			dfs(cou[i], curc);
		}
	}
}
int main()
{
	int N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i, j;
	vector<int>y;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
		y.push_back(i);
	}
	c = N;
	dfs(y, 0);
	cout << c << '\n';
	for (i = 1; i <= c; i++)
	{
		cout << ans1[i] << ' ';
	}
	cout << '\n';
	cout << N+1 << '\n';
	for (i = 0; i < ans2.size(); i++)
	{
		cout << ans2[i].first << ' ' << ans2[i].second << '\n';
	}
}