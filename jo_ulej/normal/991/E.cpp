#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

const ll mod = 1e7 + 9;

map<pair<vector<int>, bool>, ll> mem;

ll cnt(vector<int> v, bool can_use_zero)
{
	if(mem.find(make_pair(v, can_use_zero)) != mem.end())
		return mem[make_pair(v, can_use_zero)];

	ll ans = 0, sum = 0;

	for(int digit = 0; digit <= 9; ++digit)
	{
		sum += v[digit];

		if(digit == 0 && !can_use_zero)
			continue;

		if(v[digit] == 0)
			continue;

		auto u = v;
		--u[digit];

		ans += cnt(u, true);
	}

	if(sum == 0)
	{
		mem.insert(make_pair(make_pair(v, can_use_zero), 1LL));
	}
	else
	{
		mem.insert(make_pair(make_pair(v, can_use_zero), ans));
	}

	return mem[make_pair(v, can_use_zero)];
}

set<vector<int>> visited;

void dfs(vector<int> v)
{
	visited.insert(v);

	for(int digit = 0; digit <= 9; ++digit)
	{
		if(v[digit] > 1)
		{
			auto u = v;
			--u[digit];

			if(visited.find(u) == visited.end())
				dfs(u);
		}
	}
}

void solve()
{
	string num;
	vector<int> v(10, 0);

	cin >> num;

	for(auto digit: num)
		++v[digit - '0'];

	dfs(v);

	ll ans = 0;

	for(auto u: visited)
		ans += cnt(u, false);

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}