#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int anns[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, l, r, k;
		cin >> n;
		int i;
		vector<pair<int,int>>t;
		for (i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			t.push_back({ a,i });
		}
		sort(t.begin(), t.end());
		int ans = 0;
		for (i = 0; i < n; i++)
		{
			ans += t.back().first * (i / 2 + 1);
			anns[t.back().second] = (i / 2 + 1) * (i % 2 ? -1 : 1);
			t.pop_back();
		}
		cout << ans*2 << '\n';
		cout << 0 << ' ';
		for (i = 0; i < n; i++)
		{
			cout << anns[i] << ' ';
		}
		cout << '\n';
	}
}