#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
vector<pair<int,int>>inp;
int ans[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		string l;
		int N;
		cin >> N;
		inp.clear();
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			inp.push_back({ a,i });
		}
		sort(inp.begin(), inp.end());
		cin >> l;
		int d = 1;
		int s = 1;
		for (i = 0; i < N; i++)
		{
			if (l[i] == '0')
				s++;
		}
		for (i = 0; i < N; i++)
		{
			if (l[inp[i].second] == '0')
				ans[inp[i].second] = d++;
			else
				ans[inp[i].second] = s++;
		}
		for (i = 0; i < N; i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
}