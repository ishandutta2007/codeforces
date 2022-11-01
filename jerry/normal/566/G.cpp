#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, ll> p, q;
ll n, m, x, y;

void fix(map<ll, ll>& a)
{
	vector<pair<ll, ll> > st;
	for (auto it = a.begin();it != a.end();it++)
	{
		while (!st.empty() && st.back().second <= (*it).second)
			st.pop_back();
		while (st.size() >= 2)
		{
			auto A(st[st.size()-2]), B(st[st.size()-1]); auto C(*it);
			if ((B.second-A.second)*(C.first-B.first) > (C.second-B.second)*(B.first-A.first))
				break;
			st.pop_back();
		}
		st.push_back(*it);
	}
	a.clear();
	for (auto u: st)
		a[u.first] = u.second;
}

void MAX()
{
	cout << "Max\n";
	exit(0);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x >> y;
	for (int i = 0;i < n;i++)
	{
		ll a, b; cin >> a >> b;
		p[a] = max(p[a], b);
	}
	for (int i = 0;i < m;i++)
	{
		ll a, b; cin >> a >> b;
		q[a] = max(q[a], b);
	}
	fix(p); fix(q);
	if (p.begin()->second >= q.begin()->second)
		MAX();
	if (p.rbegin()->first >= q.rbegin()->first)
		MAX();
	for (auto it1 = p.begin(), it2 = q.begin();it1 != p.end() && it2 != q.end();it1++)
	{
		if (it1->first < it2->first)
			continue;
		while (it1->first >= it2->first) it2++;
		auto C(*it2);
		auto A(*--it2);
		auto B(*it1);
		if ((B.second-A.second)*(C.first-B.first) >= (C.second-B.second)*(B.first-A.first))
			MAX();
	}
	cout << "Min\n";
	return 0;
}