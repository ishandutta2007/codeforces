#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 1000000;

int f[SITO_MAX+1];
vector<int> prosti;

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

int n, m;
ll p[11], k, a[1000005], g;
int e[1000005];
ll gg[1000005][11];

bool cmp_eid(int i, int j) {
	return e[i] < e[j];
}

map<ll, basic_string<int>> mp;

basic_string<int> choose_m(basic_string<int> a, basic_string<int> b) {
	basic_string<int> out(2*m, 0);
	int elems = merge(
		a.begin(), a.end(),
		b.begin(), b.end(),
		out.begin(), cmp_eid) - out.begin();
	elems = unique(out.begin(), out.begin()+elems) - out.begin();
	elems = min(elems, m);
	out.resize(elems);
	return out;
}

basic_string<int> masks[1 << 11];
basic_string<int> inv_masks[1000005];

ll dp[2][1 << 11][12];

ll mul(ll x, ll y) {
	if (x * 1.0 * y > 1e18)
		return 1e18;
	return x * y;
}

void mn(ll& x, ll y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		g = gcd(g, a[i]);
	}

	for (int i=0; i<n; i++)
		cin >> e[i];

	if (g == 1) {
		cout << "0\n";
		return 0;
	}

	{
		auto v = factor(g);
		for (auto ee : v) {
			p[m++] = ee.first;
		}
	}

	for (int i=0; i<n; i++) {
		ll tmp = a[i], prod = 1;
		for (int j=0; j<m; j++) {
			ll p = ::p[j];
			gg[i][j] = 1;
			while (tmp % p == 0) {
				tmp /= p;
				prod *= p;
				gg[i][j] *= p;
			}
		}
		mp[prod] += i;
	}

	for (auto& ee : mp) {
		sort(ee.second.begin(), ee.second.end(), cmp_eid);
		int sz = min((int)ee.second.size(), m);
		ee.second.resize(sz);

		auto alpha = gg[ee.second[0]];

		for (int mask=0; mask<(1<<m); mask++) {
			ll prod = 1;
			for (int i=0; i<m; i++)
				if (mask & (1 << i))
					prod *= alpha[i];
			if (prod <= k) {
				for (int x : ee.second)
					inv_masks[x] += mask;
			}
		}
	}

	// obican dp
	auto ol = dp[0], nu = dp[1];
	memset(ol, 63, sizeof(dp[0]));
	ol[0][0] = 0;

	int fm = (1 << m) - 1;

	for (int i=0; i<n; i++) {
		if (inv_masks[i].size()) {
			memset(nu, 63, sizeof(dp[0]));
			for (int diff_mask : inv_masks[i]) {
				for (int mask=fm-diff_mask; mask; mask=(mask-1)&(fm-diff_mask)) {
					for (int br=0; br<m; br++) {
						mn(nu[mask | diff_mask][br+1], ol[mask][br] + e[i]);
					}
				}

				for (int br=0; br<m; br++) {
					mn(nu[0 | diff_mask][br+1], ol[0][br] + e[i]);
				}
			}

			for (int mask=0; mask<=fm; mask++) {
				for (int br=0; br<=m; br++) {
					mn(nu[mask][br], ol[mask][br]);
				}
			}

			swap(ol, nu);
		}
	}

	ll sol_all = 123123123123123123ll;
	for (int i=1; i<=m; i++) {
		// cerr << i << ' ' << ol[fm][i] << '\n';
		mn(sol_all, mul(i, ol[fm][i]));
	}

	if (sol_all == 123123123123123123ll)
		sol_all = -1;

	cout << sol_all << '\n';
}