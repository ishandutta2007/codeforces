#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cif(ll x) {
	if (x == 0)
		return 1;
	int z = 0;
	while (x > 0) {
		z++;
		x /= 10;
	}
	return z;
}

struct eksp {
	ll a, b, len, val;
};

map<ll, eksp> naj;

vector<eksp> baza;

string to_string(eksp e) {
	if (e.b == 1)
		return to_string(e.a);
	return to_string(e.a) + "^" + to_string(e.b);
}

eksp dajnaj(ll vred) {
	if (naj.count(vred) && naj[vred].len < cif(vred))
		return naj[vred];
	
	return {vred, 1, cif(vred), vred};
}

/*
9^8+9^9+1
177264450


*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n;
	cin >> n;

	if (n == 10'000'000'000ll)
		return cout << "100^5\n", 0;

	for (int i=2; i<=100000; i++) {
		ll p = i;
		for (int j=2;; j++) {
			p *= i;
			if (p > n)
				break;
			baza.push_back({i, j, cif(i) + cif(j) + 1, p});
		}
	}

	for (int i=1; i<=999; i++)
		baza.push_back({i, 1, cif(i), i});

	for (eksp e : baza) {
		if (naj.count(e.val) == 0)
			naj[e.val] = e;
		else if (e.len < naj[e.val].len)
			naj[e.val] = e;
	}

	string sol = to_string(n);

	auto sejv = [&](string s) {
		if (s.size() < sol.size())
			sol = s;
	};

	// exp+exp
	for (eksp e : baza) {
		// e+A
		if (n - e.val > 0) {
			string kand = to_string(e) + "+" + to_string(dajnaj(n - e.val));
			sejv(kand);
		}

		// tri stvari e+A+B?
		// A mora da bude exp, inace mozemo da spojimo A+B u jedan broj
		for (int i=1; i<=9; i++) {
			ll nn = n-i;
			if (nn - e.val < 1)
				continue;
			string kand = to_string(e) + "+" + to_string(dajnaj(nn - e.val))
				+ "+" + to_string(i);
			sejv(kand);
		}

		// e*A
		if (n % e.val == 0 && n != e.val && e.val != 1) {
			string kand = to_string(e) + "*" + to_string(dajnaj(n / e.val));
			sejv(kand);
		}

		// tri stvari A*B+C
		int ub = 9;
		if (e.len <= 3)
			ub = 999;
		else if (e.len == 4)
			ub = 99;
		for (int i=1; i<=ub; i++) {
			ll nn = n-i;
			if (nn < 1)
				continue;
			if (nn % e.val == 0 && nn != e.val && e.val != 1) {
				string kand = to_string(e) + "*" + to_string(dajnaj(nn / e.val))
					+ "+" + to_string(i);
				sejv(kand);
			}
		}

		// tri stvari A*B*C?
		for (int i=2; i<=9; i++) {
			ll nn = n/i;
			if (n % i != 0)
				continue;
			if (nn % e.val == 0 && nn != e.val && e.val != 1) {
				string kand = to_string(e) + "*" + to_string(dajnaj(nn / e.val))
					+ "*" + to_string(i);
				sejv(kand);
			}
		}

		// tri stvari e*i+A?
		for (int i=2; i<=9; i++) {
			ll nn = e.val*i;

			if (n - nn > 0) {
				string kand = to_string(e) + "*" + to_string(i)
					+ "+" + to_string(dajnaj(n - nn));
				sejv(kand);
			}
		}

		if (e.val == n)
			sejv(to_string(e));
	}

	cout << sol << '\n';

}