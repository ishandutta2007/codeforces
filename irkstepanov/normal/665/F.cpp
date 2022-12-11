#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int kmax = 1e7 + 10; // TODO
int mind[kmax];
int primeId[kmax];
int pi[kmax];
vector<int> primes;
int smallest[kmax];

ll ans = 0;

map<pair<ll, int>, ll> dp;
vector<int> toAnswer[kmax];

map<ll, int> magic;

void f1(ll n, int k) {
	if (n < kmax && k > smallest[n] + 1) {
		k = smallest[n] + 1;
	} else if (primes[k - 1] * primes[k - 1] > n) {
		if (magic.count(n)) {
			k = magic[n];
		} else {
			int lf = 0, rg = sz(primes);
			while (rg - lf > 1) {
				int md = (lf + rg) >> 1;
				ll p = primes[md];
				if (p * p > n) {
					rg = md;
				} else {
					lf = md;
				}
			}
			k = rg + 1;
			//assert(primes[k - 1] * primes[k - 1] > n);
			//assert(primes[k - 2] * primes[k - 2] <= n);
			magic[n] = k;
		}
	}
	pair<ll, int> p = {n, k};
	if (dp.count(p)) {
		return;
	}
	if (k == 1) {
		dp[{n, k}] = n;
		return;
	}
	if (n < kmax) {
		dp[{n, k}] = -1;
		toAnswer[n].pb(k);
		return;
	}
	dp[{n, k}] = -1;
	f1(n / primes[k - 2], k - 1);
	f1(n, k - 1);
}

vector<int> t;
int k;

void update(int pos) {
	for (pos += (k + 1); pos; pos >>= 1) {
		++t[pos];
	}
}

int get(int l, int r) {
	int ans = 0;
	for (l += (k + 1), r += (k + 1); l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
		if (l & 1) {
			ans += t[l];
		}
		if (!(r & 1)) {
			ans += t[r];
		}
	}
	return ans;
}

ll f2(ll n, int k) {
	ll add = 0;
	if (n < kmax && primes[k - 1] > n) {
		return 1;
	}
	if (n < kmax && k > smallest[n] + 1) {
		add = smallest[n] + 1 - k;
		k = smallest[n] + 1;
	} else if (primes[k - 1] * primes[k - 1] > n) {
		add = magic[n] - k;
		k = magic[n];
	}
	if (dp[{n, k}] != -1) {
		return dp[{n, k}] + add;
	}
	dp[{n, k}] = f2(n, k - 1) - f2(n / primes[k - 2], k - 1);
	return dp[{n, k}] + add;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	for (int i = 2; i < kmax; ++i) {
		mind[i] = i;
	}
	for (int k = 2; k < kmax; ++k) {
		pi[k] = pi[k - 1];
		if (mind[k] == k) {
			++pi[k];
			primes.pb(k);
			primeId[k] = sz(primes) - 1;
		}
		for (int p : primes) {
			if (p <= mind[k] && p * k < kmax) {
				mind[p * k] = p;
			} else {
				break;
			}
		}
	}

	int j = 2;
	for (int i = 0; i < sz(primes); ++i) {
		while (j < kmax && ll(primes[i]) * ll(primes[i]) > j) {
			smallest[j] = i;
			++j;
		}
	}

	ll n;
	cin >> n;
	for (ll p : primes) {
		if (p * p * p > n) {
			break;
		}
		++ans;
	}

	k = 1;
	for (int i = 0; i < sz(primes); ++i) {
		ll p = primes[i];
		if (p * p < n) {
			k = i + 1;
		} else {
			break;
		}
	}
	++k;

	f1(n, k);
	for (ll p : primes) {
		if (n / p >= kmax) {
			f1(n / p, k);
		}
	}


	/*int sum = 0;
	for (int i = 0; i < kmax; ++i) {
		sum += sz(toAnswer[i]);
	}
	cout << sum << "\n";
	cout << sz(dp) << "\n";
	return 0;*/

	t.resize(4 * (k + 1), 0);
	for (int i = 1; i < kmax; ++i) {
		int p = mind[i];
		int id = primeId[p];
		if (id >= k || i == 1) {
			id = k;
		}
		update(id);
		for (int z : toAnswer[i]) {
			dp[{i, z}] = get(z - 1, k);
		}
}

	f2(n, k);
	for (ll p : primes) {
		if (n / p >= kmax) {
			f2(n / p, k);
		}
	}

	/*for (auto it : dp) {
		cout << it.first.first << " " << it.first.second << " " << it.second << "\n";
		int cnt = 1;
		for (int i = 2; i <= it.first.first; ++i) {
			bool ok = true;
			for (int j = 0; j < it.first.second - 1; ++j) {
				if (i % primes[j] == 0) {
					ok = false;
					break;
				}
			}
			if (ok) {
				if (it.first.first == 100 && it.first.second == 5) {
					cout << "!!" << i << "\n";
				}
				++cnt;
			}
		}
		if (cnt != it.second) {
			cout << cnt << " LOLKEK\n";
			return 0;
		}
	}*/

	//cout << f2(4, 4) << "\n";

	//cout << ans << "\n";

	for (int i = 0; i < sz(primes); ++i) {
		ll p = primes[i];
		if (p * p >= n) {
			break;
		}
		if (n / p < kmax) {
			ans += pi[n / p] - (i + 1);
		} else {
			ans += f2(n / p, k) + k - 2 - (i + 1);
		}
		//cout << p << " " << ans << "\n";
	}

	cout << ans << "\n";

	/*int correct = 0;
	for (int i = 2; i <= n; ++i) {
		int p = mind[i];
		if (p * p * p == i) {
			++correct;
			continue;
		}
		if (mind[i / p] == i / p && i != p * p) {
			++correct;
		}
	}

	cout << correct << "\n";*/

}