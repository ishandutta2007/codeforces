#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct event
{
	int dir, row, c1, c2;
	event(int D, int R, int C1, int C2) : dir(D), row(R), c1(C1), c2(C2) { }
	bool operator< (const event& oth) const
	{ return (row < oth.row); }
};

map<ll, vector<pair<ll, ll> > > hor, ver;
multiset<event> evt;
ll ans;
int n;

ll bit[100007];
void b_upd(int at, ll v) { for (;at<100007;at+=at&-at) bit[at]+=v; }
ll b_qu(int at) { ll res = 0; for (;at;at-=at&-at) res += bit[at]; return res; }
ll b_qu(int lo, int hi) { return b_qu(hi)-b_qu(lo-1); }

void fix(map<ll, vector<pair<ll, ll> > >& all)
{
	for (auto it = all.begin();it != all.end();it++)
	{
		vector<pair<ll, ll> > res;
		sort(it->second.begin(), it->second.end());
		for (auto u: it->second)
			if (res.empty() || res.back().second+1 < u.first)
				res.push_back(u);
			else
				res.back().second = max(res.back().second, u.second);
		it->second = res;
		for (auto u: res)
			ans += u.second-u.first+1;
	}
}

void prepare()
{
	map<ll, int> x, y;
	for (auto it = hor.begin();it != hor.end();it++)
	{
		x[it->first];
		for (auto u: it->second)
			y[u.first], y[u.second];
	}
	for (auto it = ver.begin();it != ver.end();it++)
	{
		y[it->first];
		for (auto u: it->second)
			x[u.first], x[u.second+1];
	}
	int _ = 0;
	for (auto it = x.begin();it != x.end();it++) it->second = ++_;
	_ = 0;
	for (auto it = y.begin();it != y.end();it++) it->second = ++_;
	for (auto it = hor.begin();it != hor.end();it++) for (auto u: it->second)
		evt.emplace(0, x[it->first], y[u.first], y[u.second]);
	for (auto it = ver.begin();it != ver.end();it++) for (auto u: it->second)
		evt.emplace(1, x[u.first], y[it->first], 0),
		evt.emplace(1, x[u.second+1], y[it->first], 1);
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) hor[x1].emplace_back(min(y1, y2), max(y1, y2));
		else ver[y1].emplace_back(min(x1, x2), max(x1, x2));
	}
	fix(hor); fix(ver);
	prepare();
	while (!evt.empty())
	{
		int at = (*evt.begin()).row;
		vector<pair<int, int> > tmp;
		while (!evt.empty() && (*evt.begin()).row == at)
		{
			if ((*evt.begin()).dir)
			{
				if ((*evt.begin()).c2) b_upd((*evt.begin()).c1, -1);
				else b_upd((*evt.begin()).c1, 1);
			} else
				tmp.emplace_back((*evt.begin()).c1, (*evt.begin()).c2);
			evt.erase(evt.begin());
		}
		for (auto u: tmp) ans -= b_qu(u.first, u.second);
	}
	cout << ans << endl;
	return 0;
}