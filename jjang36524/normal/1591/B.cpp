#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int maxp[200100];
int arr[200100];
int main()
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
		vector<pair<int, int>>t;
		int cur = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			arr[i] = a;
			t.push_back({ a,i });
			if (i + 1 == N)
				cur = a;
		}
		sort(t.begin(), t.end());
		maxp[N] = 0;
		for (i = N - 1; i >= 0; i--)
		{
			maxp[i] = max(maxp[i + 1], t[i].second);
		}
		int c = 0;
		while (t.back().first!=cur)
		{
			int p = lower_bound(t.begin(), t.end(), make_pair( cur+1,0 )) - t.begin();
			c++;
			cur = arr[maxp[p]];
		}
		cout << c << '\n';
	}
}