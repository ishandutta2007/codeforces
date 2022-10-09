#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 1000000;

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

vector<pair<ll, int>> factor(ll x) {
	vector<pair<ll, int>> v;
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
int a[1000005];

ll uzmi(const vector<pair<ll, ll>>& a) {
	ll z = 0, centar = 0, sve = 0;
	for (auto [x, y] : a)
		sve += y;
	for (auto [x, y] : a) {
		z += y;
		if (2*z >= sve) {
			centar = x;
			break;
		}
	}

	z = 0;
	for (auto [x, y] : a)
		z += abs(x-centar) * y;
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	ll sum = 0;
	for (int i=0; i<n; i++)
		cin >> a[i], sum += a[i];

	auto v = factor(sum);

	ll sol = 9e18;

	for (auto [x, _] : v) {
		cerr << x << '\n';
		vector<pair<ll, ll>> pos;

		ll curr = 0, val = 0;
		for (int i=0; i<n; i++) {
			if (curr + a[i] >= x) {
				ll here = x - curr;
				pos.emplace_back(i, here);
				val += uzmi(pos);
				pos = {};
				curr = (curr + a[i]) % x;
				pos.emplace_back(i, curr);
			} else {
				pos.emplace_back(i, a[i]);
				curr += a[i];
			}
		}

		val += uzmi(pos);
		sol = min(sol, val);
	}

	if (sol > 8e18)
		sol = -1;

	cout << sol << '\n';
}