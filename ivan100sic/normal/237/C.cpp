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

int z[SITO_MAX + 1];
int a, b, k;

bool ok(int l) {
	for (int x=a; x<=b-l+1; x++) {
		if (z[x+l-1] - z[x-1] < k)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=2; i<=SITO_MAX; i++) {
		z[i] = z[i-1];
		if (f[i] == i)
			z[i]++;
	}

	cin >> a >> b >> k;

	int lo = 1, hi = b-a+1, o = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;

		//cerr << mid << " ok " << ok(mid) << '\n';

		if (ok(mid)) {
			o = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << o << '\n';
}