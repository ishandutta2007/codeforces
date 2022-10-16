#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int T, a, b, c, d;
int arr[5555];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		long long N, K;
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		int c = 0;
		int s = 0, e = N - 1;
		int a=0, b=0;
		int ans = 0;
		while (s <= e)
		{
			int m = 0;
			while (s <= e && m <= c)
			{
				m += arr[s];
				a += arr[s];
				s++;
			}
			ans++;
			c = m;
			m = 0;
			if (s <= e)
				ans++;
			while (s <= e && m <= c)
			{
				m += arr[e];
				b += arr[e];
				e--;
			}
			c = m;
		}
		cout << ans << ' ' << a << ' ' << b << "\n";
	}
}