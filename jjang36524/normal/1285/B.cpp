#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#define int long long
using namespace std;
int N, M;
int arr[100100];
int dp1[100100];
int dp2[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		int y = 0;
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
			y += arr[i];
		}
		int a = 0, b = 0;
		for (i = 0; i < N - 1; i++)
		{
			if (i == 0)
				dp1[i] = arr[i];
			else
				dp1[i] = max(0LL, dp1[i - 1]) + arr[i];
			a = max(a, dp1[i]);
		}
		for (i = 1; i < N; i++)
		{
			if (i == 1)
				dp2[i] = arr[i];
			else
				dp2[i] = max(0LL, dp2[i - 1]) + arr[i];
			b = max(b, dp2[i]);
		}
		cout << ((max(a, b) < y) ? "YES" : "NO") << '\n';
	}
}