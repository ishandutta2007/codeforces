#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
map<ll, int> divs;

ll my_gcd(ll x, ll y) {
	if (!x) return y;
	if (!y) return x;
	while (x) {
		y %= x;
		swap(x, y);
	}
	return y;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n; cin >> n;
	vector<pair<ll, int> > todo;
	for (int i = 0; i < n; ++i) {
		ll x; cin >> x;
		ll _sqrt = ll(sqrtl(x));
		if (_sqrt * _sqrt == x) {
			ll __sqrt = ll(sqrtl(_sqrt));
			if (__sqrt * __sqrt == _sqrt) {
				divs[__sqrt] += 4;
				continue;
			}
			divs[_sqrt] += 2;
			continue;
		}
		ll _cbrt = ll(powl(x, 0.33));
		while (_cbrt * _cbrt * _cbrt > x) --_cbrt;
		while (_cbrt * _cbrt * _cbrt < x) ++_cbrt;
		if (_cbrt * _cbrt * _cbrt == x) {
			divs[_cbrt] += 3;
			continue;
		}
		todo.push_back({x, 2});
	}
	for (pair<ll, int> &p: todo) {
		for (const pair<ll, int> &div: divs) {
			if (p.first % div.first == 0) {
				--p.second;
				p.first /= div.first;
				++divs[div.first];
			}
		}
	}
	vector<pair<ll, int> > new_todo;
	for (pair<ll, int> &p: todo) {
		if (p.second) {
			new_todo.push_back(p);
		}
	}

	int n1 = szof(new_todo);
	set<ll> possible_primes;
	for (int i = 0; i < n1; ++i) {
		for (int j = i + 1; j < n1; ++j) {
			ll a = new_todo[i].first;
			ll b = new_todo[j].first;
			ll g = my_gcd(a, b);
			if (g == 1) continue;
			if (g == a && new_todo[i].second == 1) {
				possible_primes.insert(g);
			} else if (g == b && new_todo[j].second == 1) {
				possible_primes.insert(g);
			} else if (g != a && g != b) {
				possible_primes.insert(g);
			}
		}
	}

	for (pair<ll, int> &p: new_todo) {
		for (ll pr: possible_primes) {
			if (p.first % pr == 0) {
				--p.second;
				++divs[pr];
				p.first /= pr;
				if (p.second > 0) {
				    p.second = 0;
				    ++divs[p.first];
				}
				break;
			}
		}
	}

	map<ll, int> dual_primes;
	for (int i = 0; i < n1; ++i) {
		pair<ll, int> &p1 = new_todo[i];
		for (int j = i + 1; j < n1; ++j) {
			pair<ll, int> &p2 = new_todo[j];
			if (p1.first == p2.first) {
				if (p1.second == 2) {
					p1.second = 0;
					dual_primes[p1.first] += 2;
				}
				if (p2.second == 2) {
					p2.second = 0;
					dual_primes[p1.first] += 2;
				}
			}
		}
	}

	ll ans = 1;
	ll mod = 998244353;
	for (const pair<ll, int> &p: divs) {
	   // cout << p.first << " " << p.second << endl;
		ans *= (p.second + 1);
		ans %= mod;
	}
	for (const pair<ll, int> &p: dual_primes) {
		ans *= (p.second / 2 + 1);
		ans %= mod;
		ans *= (p.second / 2 + 1);
		ans %= mod;
	}
	for (pair<ll, int> &p: new_todo) {
		for (int i = 0; i < p.second; ++i) {
			ans *= 2;
			ans %= mod;
		}
	}
	cout << ans << "\n";
	return 0;
}