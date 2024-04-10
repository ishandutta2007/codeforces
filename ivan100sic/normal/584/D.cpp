#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 100000;

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

bool prost(int n) {
	if (n <= 1)
		return false;
	if (n <= SITO_MAX)
		return n > 1 && f[n] == n;

	auto v = factor(n);
	return v.size() == 1 && v[0].second == 1;
}

void brut(int n) {
	if (prost(n)) {
		cout << "1\n" << n << '\n';
		return;
	}
	
	for (int i=2; i<n; i++) {
		if (prost(i) && prost(n-i)) {
			cout << "2\n" << i << ' ' << n-i << '\n';
			return;
		}
	}

	for (int i=2; i<n; i++) {
		for (int j=2; j<n-i; j++) {
			if (prost(i) && prost(j) && prost(n-i-j)) {
				cout << "3\n" << i << ' ' << j << ' ' << n-i-j << '\n';
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	if (n <= 100) {
		brut(n);
		return 0;
	}

	for (int i=3; i<=n; i++) {
		if (prost(i) && prost(n-i-3)) {
			cout << "3\n3 " << i << ' ' << n-i-3 << '\n';
			return 0;
		}
	}
}