#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ret = unordered_set<int>(a.begin(), a.end()).size();
	vector<int> count(n + 1);
	for (int i : a)
		if (i <= n)
			++count[i];
	vector<int> ss1(n + 1);
	for (int i = 0; i < n; ++i)
	{
		ss1[i + 1] = ss1[i] + (count[i] == 0 ? 1 : 0);
	}
	unordered_map<int, int> s2;
	for (int i : a)
		++s2[i];

	vector<pair<int, int>> b2;
	for (auto p2 : s2)
		b2.push_back({ p2.second, p2.first });
	sort(b2.begin(), b2.end());
	unordered_map<int, int> b3;
	for (int i = 0; i < b2.size(); ++i)
		b3[b2[i].second] = i;

	vector<int> b;
	vector<int> sd1(b2.size() + 8);
	vector<int> sd2(b2.size() + 8);

	auto add = [&](int i, int d) {
		++i;
		for (; i < sd1.size(); i += (i & (-i)))
		{
			sd1[i] += d;
			++sd2[i];
		}
	};

	auto get = [&](int i) {
		pair<int, int> ret = { 0, 0 };
		for (; i > 0; i -= (i & (-i)))
		{
			ret.first += sd1[i];
			ret.second += sd2[i];
		}
		return ret;
	};

	for (auto p2 : s2)
		if (p2.first > n)
		{
			add(b3[p2.first], p2.second);
			b.push_back(p2.second);
		}

	int next2 = n;
	for (int k = n; k > 0; k--)
	{
		for (; next2 > k; --next2)
			if (s2.count(next2))
			{
				add(b3[next2], s2[next2]);
				b.push_back(s2[next2]);
			}

		int c0 = count[k];
		int in_deg = ss1[k];
		if (in_deg > m)
			continue;
		int out_deg = c0;
		if (out_deg > m)
			continue;

		int lo = 0;
		int hi = sd1.size();
		while (hi - lo > 1)
		{
			int mi = (lo + hi) / 2;
			if (out_deg + get(mi).first <= m)
				lo = mi;
			else
				hi = mi;
		}
		int s = b.size() - get(lo).second;
		ret = min(ret, s);
	}
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("e.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; case_id++)
	{
		int ret = solve();
		printf("%d\n", ret);
	}
	return 0;
}