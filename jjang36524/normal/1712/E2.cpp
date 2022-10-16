#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>>r[200100];
int ans[200100];
int fw[201000];
void upd(int n, int k)
{
	while (n <= 200100)
	{
		fw[n] += k;
		n += n & -n;
	}
}
int ge(int n)
{
	int ans = 0;
	while (n)
	{
		ans += fw[n];
		n -= n & -n;
	}
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	for (i = 1; i <= 200000; i++)
	{
		vector<int>t;
		int j;
		for (j = 1; j*j <= i; j++)
		{
			if (i % j == 0)
			{
				t.push_back(j);
				t.push_back(i / j);
			}
		}
		sort(t.begin(), t.end());
		t.erase(unique(t.begin(), t.end()), t.end());
		while (t.size()&&t.back() >= i)
			t.pop_back();
		for (j = 0; j< t.size(); j++)
		{
			r[t[j]].push_back({ i,t.size() - 1 - j });
		}
		if (i%6==0)
		{
			r[i / 2].push_back({ i,1 });
		}
		if (i % 15 == 0)
		{
			r[i / 5*2].push_back({ i,1 });
		}
	}
	vector<pair<pair<int, int>, int>>qs;
	int T;
	cin >> T;
	for (i = 0; i < T; i++)
	{
		int a, b;
		cin >> a >> b;
		qs.push_back({ {-a,b},i });
		ans[i] += (b - a + 1) * (b - a) * (b - a - 1) / 6;
	}
	sort(qs.begin(), qs.end());
	int bef = 200001;
	for (i = 0; i < T; i++)
	{
		int j;
		for (j = bef-1; j >= -qs[i].first.first; j--)
		{
			int k;
			for (k = 0; k < r[j].size(); k++)
			{
				upd(r[j][k].first, r[j][k].second);
			}
		}
		bef = -qs[i].first.first;
		ans[qs[i].second] -= ge(qs[i].first.second);
	}
	for (i = 0; i < T; i++)
		cout << ans[i] << '\n';
}