#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int arr[5010];
int dfs(int l, int r, int m)
{
	if (l > r)
		return 0;
	pair<int, int>t = { 1LL << 40,0 };
	int i;
	for (i = l; i <= r; i++)
	{
		t = min(t, { arr[i]-m,i });
	}
	return min(r - l + 1, t.first + dfs(l, t.second - 1, m + t.first) + dfs(t.second+ 1,r, m + t.first));
}
signed main()
{
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cout << dfs(0, N - 1, 0);
}