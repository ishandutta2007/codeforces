#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
vector<string>x;
vector<int>link[101];
int ans[101];
int main()
{
	int N,M;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = N-1; i >0; i--)
	{
		cout << "? ";
		int j;
		for (j = 0; j < N; j++)
		{
			cout << 1 + (i == j) << ' ';
		}
		cout << '\n';
		cout.flush();
		int a;
		cin >> a;
		if (a && a <= i)
		{
			link[a - 1].push_back(i);
			link[i].push_back(a - 1);
		}
		cout << "? ";
		for (j = 0; j < N; j++)
		{
			cout << 2 - (i == j) << ' ';
		}
		cout << '\n';
		cout.flush();
		cin >> a;
		if (a && a <= i)
		{
			link[a - 1].push_back(i);
			link[i].push_back(a - 1);
		}
	}
	int st = -1;
	int en = -1;
	for (i = 0; i < N; i++)
	{
		if (link[i].size() == 1)
		{
			if (st == -1)
			{
				st = i;
			}
			else
				en = i;
		}
	}
	cout << "? ";
	int j;
	for (j = 0; j < N; j++)
	{
		cout << N - (N-1)*(en == j) << ' ';
	}
	cout << '\n';
	cout.flush();
	int a;
	cin >> a;
	int cur = 0;
	if (a-1 == st)
	{
		cur = st;
	}
	else
		cur = en;
	for (i = 0; i < N; i++)
	{
		ans[cur] = i + 1;
		int j;
		for (j = 0; j < link[cur].size(); j++)
		{
			if (!ans[link[cur][j]])
			{
				cur = link[cur][j];
				break;
			}
		}
	}
	cout << "! ";
	for (i = 0; i < N; i++)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
	cout.flush();
}