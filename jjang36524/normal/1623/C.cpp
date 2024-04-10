#include <bits/stdc++.h>
using namespace std;
vector<int>pos[1010];
#define int long long
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
		int i;
		vector<int>t;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			t.push_back(a);
		}
		int s = 0;
		int e = 1 << 30;
		while (s != e)
		{
			vector<int>plu(N);
			int m = (s + e+1) / 2;
			int j;
			for (j = N-1; j>=2; j--)
			{
				int di = max(0LL, min(t[j],(t[j]+plu[j] - m)) / 3);
				plu[j] -= di * 3;
				plu[j-1] += di;
				plu[j - 2] += di*2;
			}
			for (j = 0; j < N; j++)
			{
				if (plu[j] + t[j] < m)
					break;
			}
			if (j == N)
				s = m;
			else
				e = m - 1;
		}
		cout << s << '\n';
	}
}