#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 32'000'000;

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

vector<ll> factor(ll x) {
	vector<ll> v;
	for (int p : prosti) {
		if (x % p == 0) {
			while (x % p == 0) {
				x /= p;
			}
			v.push_back(p);
		}			
	}

	if (x > 1) {
		v.push_back(x);
	}
	return v;
}

template<class T>
T eea(T a, T b, T& x, T& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T g = eea(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

int q;
ll a[10005], b[10005];
bool ans[10005];
map<ll, basic_string<int>> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> q;
	for (int i=0; i<q; i++) {
		cin >> a[i] >> b[i];
		mp[b[i]] += i;
	}

	for (auto [k, q] : mp) {
		auto v = factor(k);
		if (v.size() == 0) {
			// nothing
		} else if (v.size() == 1) {
			for (int i : q) {
				ans[i] = a[i] % v[0] == 0;
			}
		} else if (v.size() == 2) {
			ll x = v[1], y = v[0], xx, yy;
			eea(x, y, xx, yy);
			xx = (xx % y + y) % y;
			// cerr << x << ' ' << y << ' ' << xx << ' ' << yy << '\n';
			for (int i : q) {
				ll ax = a[i] % y * xx % y;
				// x*ax :=: a[i] (mod y)
				ans[i] = a[i] >= x*ax;
			}
		} else {
			ll y = v[0];
			vector<ll> d(y, 4e18);
			d[0] = 0;
			set<pair<ll, int>> pq;
			pq.insert({0, 0});
			while (pq.size()) {
				auto [dx, x] = *pq.begin();
				pq.erase(pq.begin());
				for (int i=1; i<(int)v.size(); i++) {
					ll z = v[i];
					int t = (x+z) % y;
					if (d[t] > dx+z) {
						pq.erase({d[t], t});
						d[t] = dx+z;
						pq.insert({d[t], t});
					}
				}
			}
			for (int i : q) {
				ans[i] = d[a[i] % y] <= a[i];
			}
		}
	}

	for (int i=0; i<q; i++)
		cout << (ans[i] ? "YES\n" : "NO\n");
}