#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int, ll> > ch[100005];
bool vi[100005][2];
ll cac[100005][2];
int n, k;

ll dp(int at, int par, int ret)
{
	if (vi[at][ret]) return cac[at][ret];
	vi[at][ret] = true;
	for (auto u: ch[at]) if (u.first != par)
	{
		dp(u.first, at, false);
		dp(u.first, at, true);
	}
	if (ret)
	{
		vector<ll> ops;
		for (auto u: ch[at]) if (u.first != par) ops.push_back(u.second+cac[u.first][1]);
		sort(ops.begin(), ops.end(), greater<ll>());
		for (int i = 0;i < ops.size() && i < k-1;i++)
			cac[at][ret] += ops[i];
	} else
	{
		vector<pair<ll, ll> > ops;
		for (auto u: ch[at]) if (u.first != par) ops.emplace_back(u.second+cac[u.first][1], u.second+cac[u.first][0]);
		sort(ops.begin(), ops.end(), greater<pair<ll, ll> >());
		ll waste = 1ll<<62, best = 0;
		for (int i = 0;i < ops.size();i++)
			if (i < k)
			{
				cac[at][ret] += ops[i].first;
				best = max(best, ops[i].second-ops[i].first);
				waste = min(waste, ops[i].first);
			} else
				best = max(best, ops[i].second-waste);
		cac[at][ret] += best;
	}
	return cac[at][ret];
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1;i < n;i++)
	{
		int a, b; ll c; scanf("%d%d%lld", &a, &b, &c);
		ch[a].emplace_back(b, c);
		ch[b].emplace_back(a, c);
	}
	printf("%d\n", dp(0, -1, 0));
	return 0;
}