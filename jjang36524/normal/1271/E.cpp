#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int N, K;
signed main()
{
	cin >> N >> K;
	int s = 0;
	int e = N;
	while (e % 2)
		e--;
	while (s != e)
	{
		int m = (s+e)/2;
		while (m % 2)
			m++;
		int tans = 0;
		int oldm = m;
		while (m <= N)
		{
			tans += min(N-m+1,tans + 2);
			m *= 2;
		}
		m = oldm;
		if (tans < K)
			e = m-2;
		else
			s = m;
	}
	int ans = s;
	s = 2;
	e = 2 * N;
	while (e % 4 != 2)
		e--;
	while (s != e)
	{
		int m = (s + e) / 2;
		while (m % 4!=2)
			m++;
		int tans = 0;
		int oldm = m;
		while (m <= N)
		{
			tans += min(N - m + 1, tans + 2);
			m *= 2;
		}
		m = oldm;
		if (tans+1 < K)
			e = m-4;
		else
			s = m;
	}
	ans = max(ans, e / 2);
	cout << ans;
}