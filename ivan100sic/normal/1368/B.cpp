// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll f(ll b, ll s) {
	ll p = 1;
	for (ll x=0; x<10; x++) {
		if (x < s)
			p *= b;
		else
			p *= b + 1;
	}
	return p;
}

string g(ll b, ll s) {
	string t, p = "codeforces";
	for (ll x=0; x<10; x++) {
		if (x < s)
			t += string(b, p[x]);
		else
			t += string(b+1, p[x]);
	}
	return t;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ll n;
	cin >> n;

	string best(2222, 'a');

	for (ll b=1; b<=41; b++) {
		for (ll s=1; s<=10; s++) {
			if (f(b, s) >= n) {
				string t = g(b, s);
				if (t.size() < best.size())
					best = t;
			}
		}
	}

	cout << best << '\n';
}