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
		int N, M;
		cin >> M >> N;
		int i;
		vector<int>x;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			x.push_back(a);
		}
		sort(x.begin(), x.end());
		vector<int>y;
		int ans = M;
		for (i =1; i < N; i++)
		{
			y.push_back(x[i] - x[i - 1]);
		}
		y.push_back(M - x[N - 1] + x[0]);
		sort(y.begin(), y.end());
		int c = 0;
		reverse(y.begin(), y.end());
		for (i = 0; i < N; i++)
		{
			if (y[i] - (2 * c + 2) <= 1&&y[i]-1>2*c)
			{
				c++;
				ans--;
			}
			else if (y[i] - (2 * c + 2) > 1)
			{
				
				ans -= max(0LL, y[i] - (2 * c + 2));
				c += 2;
			}
				
		}
		cout << ans << '\n';
	}
}