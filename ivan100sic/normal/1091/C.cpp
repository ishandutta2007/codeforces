#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n;
	cin >> n;
	basic_string<ll> sol, divs;
	for (ll x=1; x*x<=n; x++) {
		if (n % x == 0) {
			divs += x;
			divs += n / x;
		}
	}
	sort(divs.begin(), divs.end());
	divs.resize(unique(divs.begin(), divs.end()) - divs.begin());
	for (ll d : divs)
		sol += (n-d+2)*n / (2*d);
	sort(sol.begin(), sol.end());
	for (ll x : sol)
		cout << x << ' ';
	cout << '\n';
}