#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int N;
pair<int,int> arr[100100];
int down[100100];
int pm[100100];
int ans[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M;
	cin >> N >> M;
	int i;
	int su = 0;
	for (i = 0; i < M; i++)
	{
		cin >> arr[i].first;
		su += arr[i].first;
		arr[i].second = i;
	}
	if (su < N)
	{
		cout << -1;
		return 0;
	}
	int lastpos = N;

	for (i = M - 1; i >= 0; i--)
	{
		ans[i] = min(lastpos - 1, N - arr[i].first);
		lastpos = ans[i];
	}
	if (ans[0] < 0)
	{
		cout << -1;
		return 0;
	}
	su = 0;
	for (i = 0; i < M; i++)
	{
		cout << min(su, ans[i]) + 1 << ' ';
		su += arr[i].first;
	}
}