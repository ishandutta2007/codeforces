#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define int long long
using namespace std;
int T, N;
vector<string>s;
signed main()
{
	cin >> T;
	while (T--)
	{
		int k;
		cin >> N>>k;
		int i;
		int ans = 0;
		int s = 0;
		pair<int, int>m = { 0,0 };
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			s += a;
			auto om = m;
			m = max(m, { a,i });
			if ((s - m.first) > k)
			{
				m = om;
			}
		}
		cout << ((s <= k) ? 0 : (m.second + 1)) << '\n';
	}
}