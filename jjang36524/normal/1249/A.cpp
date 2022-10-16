#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int>arr;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end());
		int s = 0;
		for (i = 1; i < N; i++)
		{
			if (arr[i] - arr[i - 1] == 1)
			{
				cout << 2 << '\n';
				s = 1;
				break;
			}
				
		}
		if (!s)
			cout << 1 << '\n';
	}
}