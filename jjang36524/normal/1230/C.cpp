#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int N, K;
int used[8][8];
int curorder[8];
vector<int>links[8];
int ans;
void howmuch()
{
	int nowans = 0;
	int i;
	memset(used, 0, sizeof(used));
	for (i = 1; i <= N; i++)
	{
		int j;
		for (j = 0; j < links[i].size(); j++)
		{
			if (!used[min(curorder[i], curorder[links[i][j]])][max(curorder[i], curorder[links[i][j]])])
			{
				nowans++;
				used[min(curorder[i], curorder[links[i][j]])][max(curorder[i], curorder[links[i][j]])] = 1;
			}
		}
	}
	ans = max(ans, nowans);
}
void gener(int n)
{
	if (n == N+1)
		howmuch();
	else
	{
		int i;
		for (i = 1; i <= 6; i++)
		{
			curorder[n] = i;
			gener(n + 1);
		}
	}
}
int main()
{
	cin >> N >> K;
	int i;
	for (i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		links[a].push_back(b);
	}
	gener(1);
	cout << ans;
}