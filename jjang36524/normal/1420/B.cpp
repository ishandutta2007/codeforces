#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int N;
int T;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int>t;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			t.push_back(a);
		}
		sort(t.begin(), t.end());
		int ans = 0;
		int s = 1;
		for (i = 0; i < 30; i++)
		{
			int r = lower_bound(t.begin(), t.end(), 2 * s)- lower_bound(t.begin(), t.end(), s);
			ans += (r) * (r - 1) / 2;
			s *= 2;
		}
		cout << ans<<'\n';
	}
}