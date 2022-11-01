#include <bits/stdc++.h>
using namespace std;

string str[205][2];
int ans[205];
int n, m;

int calc(const string &x)
{
	int v = 1;
	while (true)
	{
		bool ok = true;
		for (int k = 0;k < (1<<v);k++)
		{
			string tmp;
			for (int i = 0;i < v;i++) tmp.push_back('0'+((bool)(k&(1<<i))));
			if (x.find(tmp) == string::npos)
			{
				ok = false;
				break;
			}
		}
		if (!ok)
			return v-1;
		v++;
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> str[i][0];
		str[i][1] = str[i][0];
		ans[i] = calc(str[i][0]);
	}
	cin >> m;
	for (int i = 1;i <= m;i++)
	{
		int x, y; cin >> x >> y;
		str[n+i][0] = str[x][0]+str[y][0];
		str[n+i][1] = str[x][1]+str[y][1];
		reverse(str[n+i][1].begin(), str[n+i][1].end());
		str[n+i][0] = str[n+i][0].substr(0, 1000);
		str[n+i][1] = str[n+i][1].substr(0, 1000);
		reverse(str[n+i][1].begin(), str[n+i][1].end());
		ans[n+i] = max(ans[x], ans[y]);
		ans[n+i] = max(ans[n+i], calc(str[x][1]+str[y][0]));
		cout << ans[n+i] << '\n';
	}
	return 0;
}