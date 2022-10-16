#include <bits/stdc++.h>
using namespace std;
#define int long long
int mi[100100], ma[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int>x;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			x.push_back(a);
			mi[i + 1] = N + 1;
			ma[i + 1] = 0;
		}
		for (i = 0; i < N; i++)
		{
			mi[x[i]] = min(mi[x[i]], i + 1);
			ma[x[i]] = max(ma[x[i]], i + 1);
		}
		int li = 0;
		int c = 0;
		for (i = 0; i < N - 1; i++)
		{
			if (x[i] > x[i + 1])
				li = i + 1;
		}
		int ans = N;
		if (li == 0)
			ans = 0;
		int mx = 0;
		for (i = 0; i < N; i++)
		{
			if (mi[x[i]] == i + 1)
				c++;
			mx = max(ma[x[i]], mx);
			if (mx == i + 1)
			{
				if (li <= i + 1)
					ans = min(ans, c);
			}
		}
		cout << ans << '\n';
	}
}