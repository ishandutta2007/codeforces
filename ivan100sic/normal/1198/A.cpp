#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct smart_set {
	map<ll, ll> mp;
	ll size;

	smart_set() : size(0) {}

	void insert(ll x) {
		if (1 == ++mp[x])
			size++;
	}

	void erase(ll x) {
		if (0 == --mp[x])
			size--;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, cap;
	cin >> n >> cap;
	ll k = cap*8 / n;
	k = 1ll << min(k, 33ll);

	vector<ll> a(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll sol = n;
	smart_set s;
	for (int l=0, r=0; l<n; l++) {
		while (r<n) {
			s.insert(a[r++]);
			if (s.size > k) {
				s.erase(a[--r]);
				break;
			}
		}
		sol = min(sol, n-r+l);
		if (l < r)
			s.erase(a[l]);
	}
	cout << sol << '\n';
}