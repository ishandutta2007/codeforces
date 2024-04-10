#include <bits/stdc++.h>
using namespace std;
#define int long long
int vis[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N,K;
		cin >> N>>K;
		int i;
		vector<int>r;
		for (i = 0; i < K; i++)
		{
			int a;
			cin >> a;
			r.push_back(a);
		}
		int b = (r[0] + N - K+(N-K+1)*(1LL<<30)) / (N - K + 1)-(1LL<<30);
		for (i = 1; i < K; i++)
		{
			if (r[i] - r[i - 1] < b)
			{
				break;
			}
			else
				b = r[i] - r[i - 1];
		}
		if (i < K)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}