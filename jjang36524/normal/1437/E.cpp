#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int arr[500100];
vector<int>pos;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	int i;
	arr[0] = -(1 << 30);
	for (i = 0; i < N; i++)
	{
		cin >> arr[i+1];
		arr[i + 1] -= i;
	}
	arr[N + 1] = (1 << 30);
	pos.push_back(0);
	for (i = 0; i < K; i++)
	{
		int a;
		cin >> a;
		pos.push_back(a);
	}
	pos.push_back(N + 1);
	for (i = 0; i < K+1; i++)
	{
		if (arr[pos[i + 1]] < arr[pos[i]])
		{
			cout << -1;
			return 0;
		}
	}
	vector<int>t;
	int ans = N - K;
	for (i = 0; i < K + 1; i++)
	{
		t.clear();
		int j;
		for (j = pos[i] + 1; j < pos[i + 1]; j++)
		{
			if ((arr[j]<arr[pos[i]]) || (arr[j]>arr[pos[i + 1]]))
				continue;
			vector<int>::iterator tt;
			tt = lower_bound(t.begin(), t.end(), arr[j]+1);
			if (tt != t.end())
			{
				*tt = arr[j];
			}
			else
			{
				t.push_back(arr[j]);
			}
		}
		ans -= t.size();
	}
	cout << ans;
}