#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 3000000;

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

int p[SITO_MAX + 1];
int rub[SITO_MAX + 1];

int revs(int x) {
	int z = 0;
	while (x) {
		z = 10*z + x%10;
		x /= 10;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=1; i<=SITO_MAX; i++) {
		p[i] = p[i-1];
		if (f[i] == i && i > 1)
			p[i]++;
		rub[i] = rub[i-1];
		if (revs(i) == i)
			rub[i]++;
	}

	ll x, y;
	cin >> x >> y;

	int h = -1;
	for (int i=1; i<=SITO_MAX; i++) {
		if (p[i] * y <= x * rub[i])
			h = i;
	}
	cout << h << '\n';
}