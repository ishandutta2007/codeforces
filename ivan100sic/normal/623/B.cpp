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


int n, u, v;
int a[1000005];

double c1[1000005];

ll probaj(int p) {
	for (int i=0; i<n; i++) {
		int aip = a[i] % p;
		if (aip == 0) {
			c1[i] = 0;
		} else if (aip == 1 || aip == p-1) {
			c1[i] = v;
		} else {
			c1[i] = 1e18;
		}
	}

	double sol = 1e18, x, y, z;
	x = y = z = c1[n-1];

	for (int i=0; i<n-1; i++) {
		double xx = x + c1[i];
		double yy = min(x, y) + u;
		double zz = min(y, z) + c1[i];
		x = xx, y = yy, z = zz;
	}

	sol = min({sol, x, y, z});

	x = y = z = c1[0];

	for (int i=1; i<n; i++) {
		double xx = x + c1[i];
		double yy = min(x, y) + u;
		double zz = min(y, z) + c1[i];
		x = xx, y = yy, z = zz;
	}

	sol = min({sol, x, y, z});

	return (ll)sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> u >> v;
	for (int i=0; i<n; i++)
		cin >> a[i];

	if (n == 1) {
		cout << "0\n";
		return 0;
	}

	set<int> pr;
	for (int i=0; i<n; i+=n-1) {
		for (int j=-1; j<=1; j++) {
			for (auto [p, q] : factor(a[i] + j))
				pr.insert(p);
		}
	}
	ll sol = 1e18;
	for (int p : pr)
		sol = min(sol, probaj(p));
	cout << sol << '\n';
}