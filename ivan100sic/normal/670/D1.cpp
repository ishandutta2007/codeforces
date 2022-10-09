#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005], n, k;
int b[100005];

bool moze(ll x) {
	ll imam = k;
	for (int i=0; i<n; i++) {
		ll zajmi = a[i] * x - b[i];
		if (zajmi > 0)
			imam -= zajmi;
		if (imam < 0)
			return false;
	}
	return imam >= 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	ll l = 1, r = 2e9, o = 0;
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (moze(m)) {
			o = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}
	cout << o << '\n';
}