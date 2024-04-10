#include <bits/stdc++.h>

using namespace std;

const int two = 2;
const int N = 310;
const int S = 200100;

int n, m;
string s[two][N][N];
int k[two];
tuple<int, int, int, int> ans[two][S];
queue<char> in[N][N];

void func(int c)
{
	k[c] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			while (!in[i][j].empty()) in[i][j].pop();
			for (int x = (int)s[c][i][j].size() - 1; x >= 0; x--)
				in[i][j].push(s[c][i][j][x]);
		}
	for (int i = 1; i < m; i++)
		while (!in[0][i].empty())
		{
			ans[c][k[c]] = make_tuple(0, i, 0, 0);
			in[0][0].push(in[0][i].front());
			in[0][i].pop();
			k[c]++;
		}	
	for (int i = 1; i < n; i++)
		while (!in[i][0].empty())
		{
			ans[c][k[c]] = make_tuple(i, 0, 0, 0);
			in[0][0].push(in[i][0].front());
			in[i][0].pop();
			k[c]++;
		}	           
	while (!in[0][0].empty())
	{
		if (in[0][0].front() == '0')
		{
			ans[c][k[c]] = make_tuple(0, 0, 0, 1);
			in[0][1].push(in[0][0].front());
			in[0][0].pop();
			k[c]++;
		}
		else
		{
            ans[c][k[c]] = make_tuple(0, 0, 1, 0);
			in[1][0].push(in[0][0].front());
			in[0][0].pop();
			k[c]++;
		}
	}
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			while (!in[i][j].empty())
			{
				if (in[i][j].front() == '0')
				{
					ans[c][k[c]] = make_tuple(i, j, 0, j);
					in[0][j].push(in[i][j].front());
					in[i][j].pop();
					k[c]++;
				}
				else
				{
                    ans[c][k[c]] = make_tuple(i, j, i, 0);
					in[i][0].push(in[i][j].front());
					in[i][j].pop();
					k[c]++;
				}	
			}
	for (int i = 2; i < m; i++)
		while (!in[0][i].empty())
		{
			ans[c][k[c]] = make_tuple(0, i, 0, 1);
			in[0][1].push(in[0][i].front());
			in[0][i].pop();
			k[c]++;
		}	
	for (int i = 2; i < n; i++)
		while (!in[i][0].empty())
		{
			ans[c][k[c]] = make_tuple(i, 0, 1, 0);
			in[0][1].push(in[i][0].front());
			in[i][0].pop();
			k[c]++;
		}
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> s[0][i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> s[1][i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			reverse(s[1][i][j].begin(), s[1][i][j].end());
	func(0);
	func(1);
	reverse(ans[1], ans[1] + k[1]);
	cout << (k[0] + k[1]) << "\n";
	for (int i = 0; i < k[0]; i++)
		cout << get<0>(ans[0][i]) + 1 << " " << get<1>(ans[0][i]) + 1 << " " << get<2>(ans[0][i]) + 1 << " " << get<3>(ans[0][i]) + 1 << "\n";
	for (int i = 0; i < k[1]; i++)
		cout << get<2>(ans[1][i]) + 1 << " " << get<3>(ans[1][i]) + 1 << " " << get<0>(ans[1][i]) + 1 << " " << get<1>(ans[1][i]) + 1 << "\n";
	return 0;
}