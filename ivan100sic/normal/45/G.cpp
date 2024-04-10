#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 18003000;

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

int b[6006];
int n, m;

void dodeli(int x, int k) {
	for (int i=n; i>=1; i--) {
		if (b[i] == 0 && i <= x) {
			x -= i;
			b[i] = k;
		}
	}
}

void stampaj(vector<int> a) {
	int k = 0;
	for (int x : a)
		dodeli(x, ++k);
	for (int i=1; i<=n; i++)
		cout << b[i] << ' ';
	cout << '\n';
}

bool prost(int x) {
	return x > 1 && f[x] == x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	m = n*(n+1) / 2;

	// n = 1 nema resenje jedini
	if (n == 1) {
		cout << "-1\n";
		return 0;
	}

	// jedan broj
	if (prost(m)) {
		stampaj({m});
		return 0;
	}

	// dva broja
	for (int i=2; i<=m-2; i++) {
		if (prost(i) && prost(m-i)) {
			stampaj({i, m-i});
			return 0;
		}
	}

	// tri broja (jedan od njih je broj 3)
	for (int i=2; i<=m-2; i++) {
		if (prost(i) && prost(m-3-i)) {
			stampaj({3, i, m-i});
			return 0;
		}
	}
}