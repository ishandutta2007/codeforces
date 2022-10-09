#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	map<ll, ll> m;
	ll n;
	cin >> n;
	while (n--) {
		ll x;
		cin >> x;
		m[x]++;
	}

	if (m.size() == 1) {
		cout << "0 " << (m.begin()->second * (m.begin()->second-1) >> 1);
		cout << '\n';
	} else {
		cout << m.rbegin()->first - m.begin()->first << ' ';
		cout << m.begin()->second * m.rbegin()->second << '\n';
	}

}