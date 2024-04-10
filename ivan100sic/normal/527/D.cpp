#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r;
	bool operator< (const seg& b) const {
		return l < b.l;
	}
} a[200005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		ll x, w;
		cin >> x >> w;
		a[i] = {x-w, x+w};		
	}

	sort(a, a+n);
	int r = -2e9, z = 0;
	for (int i=0; i<n; i++) {
		if (a[i].l >= r) {
			r = a[i].r;
			z++;
		} else if (a[i].r < r) {
			r = a[i].r;
		}
	}
	cout << z << '\n';
}