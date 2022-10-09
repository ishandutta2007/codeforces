#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// Jebem vam mater, ako ovo ne bude najgore takmicenje
// u 2019 godini onda ne znam, a tek je januar. Rekord
// za ovako govnjivo takmicenje sa ovako govnjivim zadacima
// ce vrlo tesko biti oboren. Jebem vam mater jos jednom

// Uradili ste zadatak u log po upitu umesto log^2.
// Mora da ste mnogo ponosni na sebe u picku materinu

multiset<ll> w[32];
ll wsum[32];
int broj;

static inline int klasa(ll x) {
	int z = 63 - __builtin_clzll(x);
	return min(z, 31);
}

void add(int x) {
	broj++;
	int k = klasa(x);
	w[k].insert(x);
	wsum[k] += x;
}

void remove(int x) {
	broj--;
	int k = klasa(x);
	w[k].erase(w[k].find(x));
	wsum[k] -= x;
}

int solve() {
	int i = 0, jumps = 0;
	ll z = 0;
	while (1) {
		while (i < 32 && wsum[i] == 0)
			i++;
		if (i == 32)
			break;
		jumps++;
		z += wsum[i++];
		while (1) {
			if (i < 32 && (wsum[i] == 0 || (wsum[i] && *w[i].begin() <= 2*z))) {
				z += wsum[i++];
			} else {
				break;
			}
		}
	}
	return broj - jumps;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		char x; int y;
		cin >> x >> y;
		if (x == '+') {
			add(y);
		} else {
			remove(y);
		}
		cout << solve() << '\n';
	}	
}