#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N >> K;
		int i;
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			ans += (i < K) && (a > K);
		}
		cout << ans << '\n';
	}
}