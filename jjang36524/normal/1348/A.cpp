#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int T, N;
int arr[1001000];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int ans = 0;
		int i;
		for (i = 0; i < N; i++)
		{
			if (i < N / 2 - 1 || i + 1 == N)
			{
				ans += (1 << (i + 1));
			}
			else
				ans -= (1 << (i + 1));
		}
		cout << ans << '\n';
	}
}