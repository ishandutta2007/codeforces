#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M,T;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int>arr;
		int i;
		for (i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			arr.push_back(x);
		}
		sort(arr.begin(), arr.end());
		int ans = 0;
		int n = -1;
		for (i = 0; i < N; i++)
		{
			if (arr[i] <= i - n)
			{
				ans++;
				n = i;
			}
		}
		cout << ans << '\n';
	}
}