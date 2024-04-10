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
typedef long double ld;

const ll mod = 1e9 + 7;

void solve()
{
	int n;
	vector<int> arr;

	cin >> n;
	arr.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	int best_t, best_cost = INT_INF;

	for(int t = 1; t <= 200; ++t)
	{
		int cost = 0;

		for(auto x: arr)
			cost += min({abs(x - t), abs(x - t - 1), abs(x - t + 1)});

		if(cost < best_cost)
		{
			best_t = t;
			best_cost = cost;
		}
	}

	cout << best_t << " " << best_cost << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}