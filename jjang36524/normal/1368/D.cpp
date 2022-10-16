#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define int long long
using namespace std;
int N, M, a, b, d;
int arr[20];
char c[11] = "codeforces";
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		int j;
		cin >> a;
		for (j = 0; j < 20; j++)
		{
			if (a & (1 << j))
				arr[j]++;
		}
	}
	int ans = 0;
	for (i = 1; i <= N; i++)
	{
		int t = 0;
		int j;
		for (j = 0; j < 20; j++)
		{
			if (arr[j] >= i)
				t += 1 << j;
		}
		ans += t * t;
	}
	cout << ans;
}