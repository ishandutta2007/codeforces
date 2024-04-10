#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 40000;

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

bool prost(int x) {
	auto v = factor(x);
	return v.size() == 1 && v[0].second == 1;
}

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n == 2) {
			cout << "1/6\n";
			continue;
		} else if (n == 3) {
			cout << "7/30\n";
			continue;
		}
		// nadji prost broj <= n
		ll m = n;
		ll k = n+1;
		while (!prost(m))
			m--;
		while (!prost(k))
			k++;

		ll p = m-2, q = 2*m;
		// sad imam tacnu vrednost za f(m-1)
		for (ll x=m; x<=n; x++) {
			if (q == 2*m) {
				q *= k;
				p *= k;
			}
			p += 2;
		}
		ll g = gcd(p, q);
		p /= g;
		q /= g;
		cout << p << '/' << q << '\n';
	}
}