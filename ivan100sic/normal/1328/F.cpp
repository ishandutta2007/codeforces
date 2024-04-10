// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
ll fw[200005], bk[200005];
int af[200005], ab[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	map<int, int> mp;
	for (int i=0, x; i<n; i++)
		cin >> x, mp[x]++;

	vector<pair<int, int>> b(mp.begin(), mp.end());

	for (auto [x, y] : b)
		if (y >= k)
			return cout << "0\n", 0;

	int m = b.size();
	ll cost = 0;
	int amt = 0;
	for (int i=0; i<m-1; i++) {
		fw[i] = cost;
		amt += b[i].second;
		af[i] = amt;
		cost += 1ll * (b[i+1].first - b[i].first) * amt;
	}

	cost = 0;
	amt = 0;
	for (int i=m-1; i>0; i--) {
		bk[i] = cost;
		amt += b[i].second;
		ab[i] = amt;
		cost += 1ll * (b[i].first - b[i-1].first) * amt;
	}

	ll sol = 1e18;
	// gomilaj po sredini
	for (int i=0; i<m; i++) {
		// samo levo
		if (i > 0 && af[i-1] + b[i].second >= k)
			sol = min(sol, fw[i-1] + (b[i].first - b[i-1].first - 1ll) * af[i-1] + k - b[i].second);
		// samo desno
		if (i+1 < m && ab[i+1] + b[i].second >= k)
			sol = min(sol, bk[i+1] + (b[i+1].first - b[i].first - 1ll) * ab[i+1] + k - b[i].second);
		// sa obe strane
		if (i > 0 && i+1 < m)
		{
			sol = min(sol,
				fw[i-1] + (b[i].first - b[i-1].first - 1ll) * af[i-1] + 
				bk[i+1] + (b[i+1].first - b[i].first - 1ll) * ab[i+1] +
				k - b[i].second
			);
		}
	}

	cout << sol << '\n';
}

// I will still practice daily...