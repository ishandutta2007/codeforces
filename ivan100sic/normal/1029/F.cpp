#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 15'000'000;

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

void find_divisors(vector<pair<ll, int>>& v, vector<ll>& d, ll p, int i) {
	if (i == (int)v.size()) {
		d.push_back(p);
		return;
	}

	for (int j=0; j<=v[i].second; j++) {
		find_divisors(v, d, p, i+1);
		if (j != v[i].second)
			p *= v[i].first;
	}
}

map<ll, ll> tackice;

void dodaj(ll x, ll y) {

	cerr << x << ' ' << y << '\n';

	if (tackice.count(x))
		tackice[x] = min(tackice[x], y);
	else
		tackice[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b, ab;
	cin >> a >> b;
	ab = a+b;

	auto vab = factor(ab);
	auto va = factor(a);
	auto vb = factor(b);

	vector<ll> dab, da, db;
	vector<ll> rab, ra, rb;
	find_divisors(vab, dab, 1, 0);
	find_divisors(va, da, 1, 0);
	find_divisors(vb, db, 1, 0);

	for (int i=0; i<(int)da.size(); i++) {
		ll x = da[i];
		ll y = a / x;
		dodaj(x, y);
	}

	for (int i=0; i<(int)db.size(); i++) {
		ll x = db[i];
		ll y = b / x;
		dodaj(x, y);
	}

	sort(dab.begin(), dab.end());

	auto tit = tackice.begin();

	ll lo = 123123123123123123ll;
	ll sol = lo;

	for (int i=0; i<(int)dab.size(); i++) {
		ll x = dab[i];
		ll y = ab / x;

		while (tit != tackice.end() && tit->first <= x) {
			lo = min(lo, tit->second);
			++tit;
		}

		if (lo <= y) {
			sol = min(sol, x+y);
		}
	}

	cout << 2*sol;


}