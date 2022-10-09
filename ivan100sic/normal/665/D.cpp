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
int a[1005];
int c[1000005];
basic_string<int> sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}

	sol = {a[0]};

	// neka dva
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (f[a[i] + a[j]] == a[i] + a[j]) {
				sol = {a[i], a[j]};
			}
		}
	}

	if (c[1] > 0) {
		int kec = 1, kecsz = c[1];

		// vise od dva? (kec)
		for (int i=2; i<=1000000; i++) {
			if (f[1 + i] == 1 + i && c[i]) {
				if (1 + c[1] > kecsz) {
					kecsz = 1 + c[1];
					kec = i;
				}
			}
		}

		if (kecsz > (int)sol.size()) {
			sol = basic_string<int>(kecsz-1, 1) + kec;
		}
	}

	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}