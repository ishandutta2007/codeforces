#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif

#define L first
#define R second
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

void solve()
{
	int n, m;
	vector<int> arr;
	vector<pii> data;

	cin >> n >> m;
	arr.resize(n);
	data.resize(m);

	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	for(int i = 0; i < m; ++i)
	{
		cin >> data[i].L >> data[i].R;
		--data[i].L, --data[i].R;
	}

	int best_diff = -INT_INF, best_pos;

	for(int x = 0; x < n; ++x)
	{
		vector<int> narr = arr;

		for(auto d: data)
		{
			if(d.L <= x && x <= d.R)
				continue;

			for(int j = d.L; j <= d.R; ++j)
				--narr[j];
		}

		int minval = INT_INF;

		for(int i = 0; i < n; ++i)
			minval = min(minval, narr[i]);

		int diff = arr[x] - minval;

		if(diff > best_diff)
		{
			best_pos = x;
			best_diff = diff;
		}
	}

	vector<int> ndata;

	//for(auto el: data)
	for(int i = 0; i < data.size(); ++i)
	{
		auto el = data[i];

		if(best_pos < el.L || best_pos > el.R)
			ndata.push_back(i + 1);
	}

	cout << best_diff << endl;
	cout << ndata.size() << endl;

	for(auto el: ndata)
		cout << el << " ";

	cout << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}