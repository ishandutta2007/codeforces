#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 1000;

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

int z = 0;
ll sol = 8e18;

ll ofmul(ll x, ll y) {
	if (x * 1.0 * y < 8e18)
		return x * y;
	else
		return 8e18;
}

ll prod(basic_string<int> v) {
	ll p = 1;
	for (int i=0; i<(int)v.size(); i++) {
		int x = v[i] - 1;
		while (x--)
			p = ofmul(p, prosti[i]);
	}
	return p;
}

void rek(ll p, basic_string<int> v) {
	if (p == 1) {
		sol = min(sol, prod(v));
	}

	int ub = -1;

	if (v.size() == 0)
		ub = p;
	else
		ub = v.back();

	for (int x = 2; x<=ub; x++)
		if (p % x == 0)
			rek(p / x, v + x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	rek(n, {});
	cout << sol << '\n';
}