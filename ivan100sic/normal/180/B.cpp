#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 100000;

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


bool is2(ll b, ll d) {
	ll p = 1;
	for (int i=1; i<=8; i++) {
		p *= b;
		if (p % d == 0) {
			return true;
		}
	}
	return false;
}

bool is3(ll b, ll d) {
	return (b-1) % d == 0;
}

bool is11(ll b, ll d) {
	return set<ll>{b % d, b*b % d} == set<ll>{1ll, d-1};
}

bool is2311(ll b, ll d) {
	return is2(b, d) || is3(b, d) || is11(b, d);
}

ll pw(ll x, ll y) {
	ll p = 1;
	while (y--)
		p *= x;
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll b, d;
	cin >> b >> d;
	// 2-type je ako postoji stepen b koji je deljiv sa d
	{
		ll p = 1;
		for (int i=1; i<=8; i++) {
			p *= b;
			if (p % d == 0) {
				cout << "2-type\n" << i << '\n';
				return 0;
			}
		}
	}
	// 3-type je ako d deli b-1
	if (is3(b, d)) {
		cout << "3-type\n";
		return 0;
	}
	// 11-type je ako d deli bb-1
	if (is11(b, d)) {
		cout << "11-type\n";
		return 0;
	}
	// 6-type ako mozemo da ga faktorisemo na ove tipove
	// dovoljno je da proverimo proste faktore
	bool ok = 1;
	for (auto p : factor_small(d))
		ok &= is2311(b, pw(p.first, p.second));
	if (ok) {
		cout << "6-type\n";
		return 0;
	}	
	cout << "7-type\n";	
}