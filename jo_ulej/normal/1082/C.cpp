#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

int n, m;
vector<vector<ll>> data, prefsum;
vector<ll> fsum(100100, 0);

ll find_sum(int k)
{
	return fsum[k];

	ll ans = 0;

	for(int i = 0; i < m; ++i)
	{
		ll delta = 0;

		if(k < prefsum[i].size())
			delta = prefsum[i][k];

		if(delta > 0)
			ans += delta;
	}

	return ans;
}

int main(int argc, char** argv)
{
	int max_k = 0;
	FAST_IO
	
	cin >> n >> m;
	data.resize(m);
	prefsum.resize(m);

	for(int i = 0; i < n; ++i)
	{
		int s, r;
		cin >> s >> r;

		--s;

		data[s].push_back(r);
	}

	for(int i = 0; i < m; ++i)
	{
		max_k = max(max_k, (int)data[i].size());

		sort(data[i].begin(), data[i].end());
		reverse(data[i].begin(), data[i].end());

		prefsum[i].resize(data[i].size() + 1);

		prefsum[i][0] = 0;

		for(int j = 1; j <= data[i].size(); ++j)
		{
			prefsum[i][j] = prefsum[i][j - 1] + data[i][j - 1];

			if(prefsum[i][j] > 0)
				fsum[j] += prefsum[i][j];
		}
	}

	ll ans = 0;

	for(int k = 0; k <= max_k; ++k)
		ans = max(ans, (ll)find_sum(k));

	cout << ans << endl;

    return 0;
}