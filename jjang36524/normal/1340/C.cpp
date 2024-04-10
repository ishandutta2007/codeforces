#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
int N, K, r,g;
int vis[10010][1001];
int arr[10010];
int tim[10010];
int tt;
queue<int>nw;
void dfs(int n, int t)
{
	if (t > g)
		return;
	
	if (vis[n][t])
		return;
	vis[n][t] = tim[tt]+1;
	if (t == g)
	{
		nw.push(n);
		tim[n] = tim[tt] + 1;
		return;
	}
	
	if (n)
	{
		dfs(n - 1, t + arr[n] - arr[n - 1]);
	}
	if (n < K-1)
	{
		dfs(n + 1, t - arr[n] + arr[n + 1]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	int i;
	for (i = 0; i < K; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+K);
	cin >> g >> r;
	nw.push(0);
	vis[0][g] = 1;
	while (nw.size())
	{
		tt = nw.front();
		nw.pop();
		dfs(tt, 0);
	}
	int ans = 1<<30;
	for (i = 0; i <= g; i++)
	{
		if (vis[K - 1][i])
		{
			ans = min(ans, (vis[K - 1][i] - 1) * (g + r) + i);
		}
	}
	cout << (ans==1<<30?-1:ans);
}