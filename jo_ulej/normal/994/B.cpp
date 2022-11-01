#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

struct Knight
{
	ll power, cost, ans = -1, idx;

	bool operator<(const Knight& other) const
	{
		if(ans == -1)
			return power < other.power;

		return idx < other.idx;
	}
};

int main(int argc, char** argv)
{
	int n, k;
	vector<Knight> knights;

	cin >> n >> k;

	knights.resize(n);

	for(int i = 0; i < n; ++i)
		knights[i].idx = i;

	for(int i = 0; i < n; ++i)
		cin >> knights[i].power;

	for(int i = 0; i < n; ++i)
		cin >> knights[i].cost;

	sort(knights.begin(), knights.end());

	vector<ll> best_prices;

	for(int i = 0; i < n; ++i)
	{
		knights[i].ans = knights[i].cost;

		for(int j = 0; j < best_prices.size(); ++j)
			knights[i].ans += best_prices[j];

		if(k == 0)
			continue;

		if(best_prices.size() < k)
		{
			best_prices.push_back(knights[i].cost);

			sort(best_prices.begin(), best_prices.end());
		}
		else if(knights[i].cost > best_prices[0])
		{
			best_prices[0] = knights[i].cost;

			sort(best_prices.begin(), best_prices.end());
		}
	}

	sort(knights.begin(), knights.end());

	for(int i = 0; i < n; ++i)
		cout << knights[i].ans << " ";

	cout << endl;

	return 0;
}