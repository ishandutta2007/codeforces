#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 1000000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<pair<int, int>> factor_small(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

vector<pair<ll, int>> factor(ll x) {
	vector<pair<ll, int>> v;
	for (int p : prosti) {
		if (x % p == 0) {
			int c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.push_back({p, c});
		}			
	}

	if (x > 1) {
		v.push_back({x, 1});
	}
	return v;
}

int n;
ll a[1000005];

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	uniform_int_distribution<int> uid(0, n-1);

	ll sol = 1;

	for (int step=0; step<13; step++) {
		int x = uid(eng);
		swap(a[0], a[x]);
		auto v = factor(a[0]);
		int k = v.size();
		vector<int> q(1 + k);
		q[0] = 1;
		for (int i=0; i<k; i++)
			q[i+1] = q[i] * (v[i].second + 1);

		vector<int> f(q[k]);

		map<ll, int> cache;

		for (int i=0; i<n; i++) {
			ll z = gcd(a[0], a[i]);
			int t = 0;
			if (cache.count(z)) {
				t = cache[z];
			} else {
				ll z0 = z;
				for (int j=0; j<k; j++) {
					while (z % v[j].first == 0) {
						t += q[j];
						z /= v[j].first;
					}
				}
				cache[z0] = t;
			}
			f[t]++;
		}

		for (int j=0; j<k; j++) {
			for (int i=f.size()-1; i>=0; i--) {
				if (i / q[j] % (v[j].second + 1) != 0) {
					f[i - q[j]] += f[i];
				}
			}
		}

		for (int i=0; i<(int)f.size(); i++) {
			if (f[i]*2 >= n) {
				ll z = 1;
				for (int j=0; j<k; j++) {
					int r = i / q[j] % (v[j].second + 1);
					while (r--)
						z *= v[j].first;
				}
				sol = max(sol, z);
			}
		}
	}

	cout << sol << '\n';
}