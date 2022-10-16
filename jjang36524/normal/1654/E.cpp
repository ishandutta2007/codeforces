#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[80001000];
int arr[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
		arr[i] += 1LL << 25;
	}
	int ans = 0;
	for (i = -300; i <= 300; i++)
	{
		int j;
		for (j = 0; j < N; j++)
		{
			c[arr[j] + j * i]++;
			ans = max(ans, c[arr[j] + j * i]);
		}
		for (j = 0; j < N; j++)
		{
			c[arr[j] + j * i]--;
		}
	}
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = i-400; j <= i + 400; j++)
		{
			if (j < 0 || j >= N)
				continue;
			if (i == j)
				continue;
			int di = arr[j] - arr[i];
			int v = abs(j - i);
			if (abs(di) % v == 0)
			{
				c[di / (j-i)+(1LL<<20)]++;
				ans = max(ans, c[di / (j-i) + (1LL << 20)]+1);
			}
		}
		for (j = i - 400; j <= i + 400; j++)
		{
			if (j < 0 || j >= N)
				continue;
			if (i == j)
				continue;
			int di = arr[j] - arr[i];
			int v = abs(j - i);
			if (abs(di) % v == 0)
			{
				c[di / (j-i) + (1LL << 20)]--;
			}
		}
	}
	cout << N - ans;
}