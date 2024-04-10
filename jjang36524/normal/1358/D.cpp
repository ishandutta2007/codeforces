#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define int long long
int T;
int arr[400100];
int psum[400100];
int npsum[400100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N,x;
	cin >> N>>x;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
		arr[i + N] = arr[i];
	}
	for (i = 0; i < 2 * N; i++)
	{
		if (i == 0)
		{
			psum[i] = arr[i];
			npsum[i] = arr[i] * (arr[i] + 1) / 2;
		}
		else
		{
			psum[i] = arr[i]+psum[i-1];
			npsum[i] = arr[i] * (arr[i] + 1) / 2+npsum[i-1];
		}
	}
	int s = lower_bound(psum, psum + 2*N, x)-psum;
	int ans = 0;
	for (i = s; i < 2 * N; i++)
	{
		int r= upper_bound(psum, psum + 2 * N, psum[i]-x) - psum;
		int a = npsum[i] - npsum[r];
		a += (psum[r] - psum[i] + x) * (arr[r] * 2 + psum[i] - x - psum[r] + 1) / 2;
		ans = max(ans, a);
	}
	cout << ans;
}