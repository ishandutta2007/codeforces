#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 2000000;

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

int n;
int a[100005];
set<int> ok;

int izbacen[2000005];
int c[2000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int prebacio = 0;

	for (int i=2; i<=2000000; i++) {
		ok.insert(i);
		c[i] = 1;
	}

	for (int i=1; i<=n; i++) {
		int x, lb;
		cin >> x;
		if (prebacio)
			lb = 1;
		else
			lb = x;

		int y = *ok.lower_bound(lb);
		cout << y << ' ';
		if (y > x)
			prebacio = 1;

		auto v = factor_small(y);
		for (auto e : v) {
			int p = e.first;
			if (!izbacen[p]) {
				izbacen[p] = 1;
				for (int i=p; i<=SITO_MAX; i+=p)
					if (c[i]) {
						ok.erase(i);
						c[i] = 0;
					}
			}
		}
	}

	cout << '\n';
}