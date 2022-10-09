#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];

bool moze(ll x) {
	ll smem = 0;
	for (int i=0; i<n; i++) {
		if (a[i] > x)
			return false;
		smem += x - a[i];
	}
	return x <= smem;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	ll l = 0, r = 3e9, o = -1;
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (moze(m)) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	cout << o << '\n';
}