#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
int T, N,M, a, b, c, d;
int ans[500001][2];
vector<int>pri;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	memset(ans, -1, sizeof(ans));
	int i;
	for (i = 2; i < 3200; i++)
	{
		int p = 1;
		int j;
		for (j = 0; j < pri.size(); j++)
		{
			if (i % pri[j] == 0)
				p = 0;
		}
		if (p)
			pri.push_back(i);
	}
	for (i = 0; i < N; i++)
	{
		cin >> a;
		int j;
		int p = 0;
		int oa = a;
		for (j = 0; j < pri.size(); j++)
		{
			while (a % pri[j] == 0)
			{
				p = pri[j];
				a /= pri[j];
			}
			if (p)
				break;
		}
		if (!(j == pri.size() || a == 1))
		{
			ans[i][0] = a;
			ans[i][1] = oa/a;
		}
	}
	for (i = 0; i < N; i++)
	{
		cout << ans[i][0] << ' ';
	}
	cout << '\n';
	for (i = 0; i < N; i++)
	{
		cout << ans[i][1] << ' ';
	}
}