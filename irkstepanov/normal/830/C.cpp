#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

struct pll {
	ll k, b;
	pll() : k(0), b(0) {}
	pll(ll k, ll b) : k(k), b(b) {}
	pll operator+(const pll& other) const {
		return {k + other.k, b + other.b};
	}
	pll& operator+=(const pll& other) {
		k += other.k;
		b += other.b;
		return *this;
	}
	pll& operator-=(const pll& other) {
		k -= other.k;
		b -= other.b;
		return *this;
	}
};

const int buben = 32000;
const ll inf = 1e12;
map<ll, pll> mapa;

void add(ll lf, ll rg, ll k, ll b) {
	//cout << lf << " " << rg << " " << k << " " << b << "\n";
	mapa[lf] += {k, b};
	mapa[rg + 1] -= {k, b};
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	
	int n;
	ll lim;
	cin >> n >> lim;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	ll ans = 1;
	for (ll d = 2; d <= buben; ++d) {
		ll sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += (d - a[i] % d) % d;
			if (sum > lim) {
				break;
			}
		}
		if (sum <= lim) {
			ans = max(ans, d);
		}
	}

	for (int i = 0; i < n; ++i) {
		add(max(a[i], ll(buben) + 1), inf, 1, -a[i]);
		for (int d = 1; ; ++d) {
			ll rg = a[i] / d;
			ll lf = max(a[i] / (d + 1), ll(buben + 1));
			if (a[i] % rg == 0) {
				--rg;
			}
			if (a[i] % lf) {
				++lf;
			}
			if (lf > rg) {
				break;
			}
			if (lf == rg) {
				add(lf, rg, 0, (lf - a[i] % lf) % lf);
			} else {
				ll val1 = (lf - a[i] % lf) % lf;
				ll val2 = (lf + 1 - a[i] % (lf + 1)) % (lf + 1);
				add(lf, rg, val2 - val1, val1 - (val2 - val1) * lf);
			}
		}
	}

	pll curr;
	for (auto it = mapa.begin(); it != mapa.end(); ++it) {
		curr += it->second;
		if (it == --mapa.end()) {
			break;
		}
		auto nx = it;
		++nx;
		ll lf = it->first, rg = nx->first - 1;
		assert(curr.k >= 0);
		if (curr.k == 0) {
			if (curr.b <= lim) {
				ans = max(ans, rg);
			}
			continue;
		}
		if (curr.b > lim) {
			continue;
		}
		ll pos = (lim - curr.b) / curr.k;
		if (pos >= lf && pos <= rg) {
			ans = max(ans, pos);
		}
		if (curr.b + curr.k * lf <= lim) {
			ans = max(ans, lf);
		}
		if (curr.b + curr.k * rg <= lim) {
			ans = max(ans, rg);
		}
	}

	cout << ans << "\n";

}