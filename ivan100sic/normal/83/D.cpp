// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 40'000'000;

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
		f[1] = 2.01e9;
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

vector<pair<int, int>> factor(int x) {
	vector<pair<int, int>> v;
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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, k;
	cin >> a >> b >> k;

	// k mora da bude prost broj inace nema resenja
	{
		auto v = factor(k);
		if (v.size() > 1 || v[0].second > 1)
			return cout << 0, 0;
	}

	if (k <= 47) {
		vector<int> mali = {k};
		for (int i=2; i<k; i++)
			if (f[i] == i)
				mali.push_back(i);

		auto c = [&](int x) {
			int n = mali.size();
			ll z = 0;
			for (int mask=1; mask<(1<<n); mask+=2) {
				ll p = 1;
				int sgn = -1;
				for (int i=0; i<n; i++) {
					if (mask & (1 << i)) {
						p *= mali[i];
						sgn = -sgn;
					}
				}
				z += sgn * x / p;
			}
			return z;
		};

		cout << c(b) - c(a-1);
	} else {
		int c = 0;
		for (ll x=k; x<=b; x+=k) {
			if (x >= a && f[x / k] >= k)
				c++;
		}
		cout << c;
	}
}

// I will still practice daily...