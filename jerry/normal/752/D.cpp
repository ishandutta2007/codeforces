#include <bits/stdc++.h>
using namespace std;

map<string, vector<int> > all;
int n, k, ans, extra;

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0;i < n;i++)
	{
		string tmp; int val;
		cin >> tmp >> val;
		all[tmp].push_back(val);
	}
	for (auto it = all.begin();it != all.end();it++)
	{
		string tmp = it->first;
		reverse(tmp.begin(), tmp.end());
		if (tmp == it->first) continue;
		auto it2 = all.find(tmp);
		if (it2 == all.end()) continue;
		sort(it->second.begin(), it->second.end());
		sort(it2->second.begin(), it2->second.end());
		while (!it->second.empty() && !it2->second.empty())
		{
			int va = it->second.back()+it2->second.back();
			if (va > 0)
			{
				ans += va;
				it->second.pop_back();
				it2->second.pop_back();
			} else break;
		}
	}
	for (auto it = all.begin();it != all.end();it++)
	{
		string tmp = it->first;
		reverse(tmp.begin(), tmp.end());
		if (tmp != it->first) continue;
		sort(it->second.begin(), it->second.end());
		while (it->second.size() >= 2)
		{
			int va = *it->second.rbegin()+*++it->second.rbegin();
			if (va > 0)
			{
				extra = max(extra, -*++it->second.rbegin());
				ans += va;
				it->second.pop_back();
				it->second.pop_back();
			} else break;
		}
	}
	for (auto it = all.begin();it != all.end();it++)
	{
		string tmp = it->first;
		reverse(tmp.begin(), tmp.end());
		if (tmp == it->first && !it->second.empty()) extra = max(extra, it->second.back());
	}
	ans += extra;
	printf("%d\n", ans);
	return 0;
}