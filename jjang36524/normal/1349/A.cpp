#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int N;
vector<signed>arr[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		int j;
		int x = a;
		for (j = 2; j <= sqrt(x)+1; j++)
		{
			int s = 0;
			while (a % j == 0)
			{
				s++;
				a /= j;
			}
			arr[j].push_back(s);
		}
		if (a>1)
			arr[a].push_back(1);
	}
	long long ans = 1;
	for (i = 2; i <= 200000; i++)
	{
		if (arr[i].size() <= N - 2)
			continue;
		sort(arr[i].begin(), arr[i].end());
		int j;
		for (j = 0; j < arr[i][1-N+arr[i].size()]; j++)
		{
			ans *= i;
		}
	}
	cout << ans;
}