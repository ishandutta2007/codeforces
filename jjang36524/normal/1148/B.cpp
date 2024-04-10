#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>ac, bc;
signed main()
{
	int N, M,a,b,c;
	cin >> N >> M>>a>>b>>c;
	int i;
	for (i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		ac.push_back(x);
	}
	for (i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		bc.push_back(x);
	}
	int ans = 0;
	for (i = 0; i <= c; i++)
	{
		if (i >= ac.size())
		{
			cout << -1;
			return 0;
		}
		int p = lower_bound(bc.begin(), bc.end(), ac[i] + a) - bc.begin() + c - i;
		if(p>=bc.size())
		{
			cout << -1;
			return 0;
		}
		ans = max(ans, bc[p] + b);
	}
	cout << ans;
}