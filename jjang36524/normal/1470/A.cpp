#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int k[300100], c[300100];
signed main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		int i;
		for (i = 0; i < N; i++)
		{
			cin >> k[i];
			k[i]--;
		}
		for (i = 0; i < M; i++)
		{
			cin >> c[i];
		}
		sort(k, k + N);
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			if (i >= M)
				c[i] = 1LL << 60;
			ans += min(c[k[N-i-1]] , c[i]);
		}
		cout << ans << '\n';
	}
}