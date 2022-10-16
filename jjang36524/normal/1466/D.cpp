#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
using namespace std;
int T, N;
vector<int>t[1001000];
int arr[1000100];
long long ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		priority_queue<int>xy;
		ans = 0;
		cin >> N;
		int i;
		for (i = 1; i <= N; i++)
		{
			t[i].clear();
			cin >> arr[i];
			ans += arr[i];
		}
		for (i = 1; i < N; i++)
		{
			int a, b;
			cin >> a >> b;
			t[a].push_back(b);
			t[b].push_back(a);
		}
		for (i = 1; i <= N; i++)
		{
			int j;
			for (j = 1; j < t[i].size(); j++)
			{
				xy.push(arr[i]);
			}
		}
		cout << ans << ' ';
		while (xy.size())
		{
			ans += xy.top();
			xy.pop();
			cout << ans << ' ';
		}
		cout << '\n';
	}
}