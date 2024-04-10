#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 32000;

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

int n, a[5005], z[5005];
set<int> bad;

int numval(int x) {
	static map<int, int> cache;
	if (cache.count(x))
		return cache[x];
	int y = 0;
	auto v = factor(x);
	for (auto [p, a] : v) {
		if (bad.count(p)) {
			y -= a;
		} else {
			y += a;
		}
	}
	return cache[x] = y;
}

vector<int> bitni;

void ad(map<int, int>& mp, int x, int y) {
	auto it = mp.find(x);
	if (it == mp.end()) {
		mp[x] = y;
	} else {
		it->second = max(it->second, y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int m;
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i], z[i] = gcd(z[i-1], a[i]);

	for (int x=1; x*x <= a[1]; x++) {
		if (a[1] % x == 0) {
			bitni.push_back(x);
			if (x*x < a[1])
				bitni.push_back(a[1] / x);
		}
	}
	sort(begin(bitni), end(bitni));

	while (m--) {
		int x;
		cin >> x;
		bad.insert(x);
	}

	map<int, int> ol;
	ol[1] = 0;

	for (int i=n; i>=1; i--) {
		map<int, int> nu;
		for (auto [coef, val] : ol) {
			int d = z[i] / coef;
			ad(nu, coef * d, val + numval(a[i]) - numval(coef * d));
			ad(nu, coef, val + numval(a[i]) - numval(coef));
		}
		swap(ol, nu);
	}

	int sol = -1e9;
	for (auto [x, y] : ol)
		sol = max(sol, y);
	cout << sol << '\n';
}

// 12 12 6 6 3 3 3 3 1 1 1 1 1 1 1
//             ^
//  4  4 2 2 1 1 .................