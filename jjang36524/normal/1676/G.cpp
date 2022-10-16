#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<int>link[4010];
int st[4010][2];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N;
		int i;
		for (i = 1; i <= N; i++)
		{
			link[i].clear();
			st[i][0] = st[i][1] = 0;
		}
		for (i = 2; i <= N; i++)
		{
			int a;
			cin >> a;
			link[a].push_back(i);
		}
		string a;
		cin >> a;
		for (i = 1; i <= N; i++)
		{
			if (a[i - 1] == 'W')
				st[i][0] ++;
			else
				st[i][1]++;
		}
		int ans = 0;
		for (i = N; i >= 1; i--)
		{
			int j;
			for (j = 0; j < link[i].size(); j++)
			{
				st[i][0] += st[link[i][j]][0];
				st[i][1] += st[link[i][j]][1];
			}
			if(st[i][0]==st[i][1])
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
}