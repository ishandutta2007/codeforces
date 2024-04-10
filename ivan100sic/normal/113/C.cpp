#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 20000;

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


bool k1[25000000 + 55];
bool k5[25000000 + 55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int l, r;
	cin >> l >> r;

	// 12k + [1, 5]
	for (int i : prosti) {
		for (int j=i*i; j<=300000000; j+=2*i)
			if (j % 12 == 1)
				k1[j / 12] = 1;
			else if (j % 12 == 5)
				k5[j / 12] = 1;
	}

	int z = 0;

	for (int i=13, j=1; i<=r; i+=12, j++) {
		if (i >= l) {
			if (!k1[j])
				z++;
		}
	}

	for (int i=5, j=0; i<=r; i+=12, j++) {
		if (i >= l) {
			if (!k5[j])
				z++;
		}
	}

	if (l <= 2 && 2 <= r)
		z++;

	cout << z << '\n';
}