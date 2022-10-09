// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

vector<pair<ll, int>> factor_small(ll x) {
	vector<pair<ll, int>> v;
	while (x > 1) {
		ll p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

vector<pair<ll, int>> factor(ll x) {
	if (x < SITO_MAX)
		return factor_small(x);
	vector<pair<ll, int>> v;
	for (int p : prosti) {
		if (p*1ll*p > x)
			break;
		if (x % p == 0) {
			int c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.push_back({p, c});
			if (v.size() == 2)
				return v;
		}
	}

	if (x > 1) {
		v.push_back({x, 1});
	}
	return v;
}

vector<ll> d;
vector<ll> the_prime_orig;
vector<vector<ll>> compat;
int the_prime[10005];
bool used[10005];
// malo bolje u odnosu na set
gp_hash_table<ll, bool> sols;
// gp_hash_table<ll, bool> used; 

struct dvojkat {
	ll v;
	int pos1, tp1, tp2;
};

gp_hash_table<ll, vector<dvojkat>> dvojke;

// broj koji moze da se predstavi kao proizvod najvise 2 druga broja
void rek3d(ll x, int pos, ll prod) {
	// jedan broj?
	{
		auto it = lower_bound(begin(d), end(d), x);
		if (it != end(d) && *it == x) {
			int i = it - begin(d);
			if (!used[the_prime[i]]) {
				sols.insert({prod * (x - 1), false});
			}
		}
	}

	// dva broja?
	for (auto dvojka : dvojke[x]) {
		if (dvojka.pos1 < pos)
			return;
		if (!used[dvojka.tp1] && !used[dvojka.tp2])
			sols.insert({prod * dvojka.v, false});
	}
}

const int SZ = 15'000'041;
ll hh[SZ + 1000];
int hv[SZ + 1000];

int hfind(ll k) {
	int p = ull(k) % SZ;
	while (hh[p] != k && hh[p] != -1)
		p++;
	if (hh[p] == -1)
		hh[p] = k;
	return p;
}

ll hsh(ll x, ll y) {
	return x + 5943757383788725ull * y;
}

void rek(ll x, int pos, ll prod) {
	if (x == 1) {
		sols.insert({prod, false});
		return;
	}

	int hp = hfind(hsh(x, prod));
	int hi = min((int)d.size(), hv[hp]);
	hv[hp] = min(hv[hp], pos);
	
	for (int i=pos; i<hi; i++) {
		if (d[i] > x)
			return;
		if (i+2 >= (int)d.size() || ld(d[i]) * d[i+1] * d[i+2] > x) {
			rek3d(x, i, prod);
			return;
		}

		if (!used[the_prime[i]] && x % d[i] == 0) {
			used[the_prime[i]] = 1;
			rek(x / d[i], pos+1, prod * (d[i] - 1));
			used[the_prime[i]] = 0;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(hh, 0xff, sizeof hh);
	memset(hv, 63, sizeof hv);

	ll a;
	cin >> a;
	set<ll> ds;
	for (ll x=1; x*x<=a; x++) {
		if (a % x == 0) {
			ds.insert(x);
			ds.insert(a / x);
		}
	}

	ds.erase(1);
	ds.erase(2);
	for (ll x : ds) {
		auto v = factor(x-1);
		if (v.size() == 1) {
			d.push_back(x);
			// cerr << x << ' ';
			the_prime_orig.push_back(v[0].first);
		}
	}

	auto tmp = the_prime_orig;
	sort(begin(tmp), end(tmp));
	tmp.erase(unique(begin(tmp), end(tmp)), end(tmp));
	for (int i=0; i<(int)the_prime_orig.size(); i++)
		the_prime[i] = lower_bound(begin(tmp), end(tmp), the_prime_orig[i]) - begin(tmp);

	for (int i=(int)d.size()-1; i>=0; i--) {
		for (int j=i+1; j<(int)d.size(); j++) {
			if (1.0 * d[i] * d[j] > 1e18)
				break;
			ll x = d[i] * d[j];
			if (a % x == 0 && the_prime[i] != the_prime[j]) {
				dvojke[x].push_back({(d[i]-1) * (d[j]-1), i, the_prime[i], the_prime[j]});
			}
		}
	}

	// cerr << '\n';
	cerr << d.size() << '\n';

	rek(a, 0, 1);

	cout << sols.size() << '\n';

}

// I will still practice daily...