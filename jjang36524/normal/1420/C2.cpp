#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define int long long
int stree[1 << 20][4];
int treeN;
void calculate(int ind, int money)
{
	if (ind >= treeN)
	{
		stree[ind][0] = money;
		stree[ind][3] = -money;
	}
	else
	{
		stree[ind][3] = max(stree[ind * 2][2] + stree[ind * 2 + 1][3], stree[ind * 2][3] + stree[ind * 2 + 1][1]);
		stree[ind][2] = max(stree[ind * 2][2] + stree[ind * 2 + 1][2], stree[ind * 2][3] + stree[ind * 2 + 1][0]);
		stree[ind][1] = max(stree[ind * 2][0] + stree[ind * 2 + 1][3], stree[ind * 2][1] + stree[ind * 2 + 1][1]);
		stree[ind][0] = max(stree[ind * 2][0] + stree[ind * 2 + 1][2], stree[ind * 2][1] + stree[ind * 2 + 1][0]);
	}
}
void update(int n, int m)
{
	n += treeN;
	while (n)
	{
		calculate(n, m);
		n /= 2;
	}
}
int arr[300100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N,Q;
		cin >> N >> Q;
		int i;
		for (treeN = 1; treeN < N; treeN *= 2);
		for (i = 1; i < 2 * treeN; i++)
		{
			stree[i][0] = stree[i][3] = (-1LL<<60);
			stree[i][1] = stree[i][2] = 0;
		}
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
			update(i,arr[i]);
		}
		cout << max(stree[1][0], stree[1][1])<<'\n';
		while (Q--)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			swap(arr[a], arr[b]);
			update(a, arr[a]);
			update(b, arr[b]);
			cout << max(stree[1][0], stree[1][1]) << '\n';
		}

	}
}