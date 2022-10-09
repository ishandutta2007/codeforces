#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct rest {
	int l, r;
	bool operator< (const rest& o) const {
		return l < o.l;
	}
} a[500005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].l >> a[i].r;
	}
	sort(a, a+n);
	int z = 0, r = -1;
	for (int i=0; i<n; i++) {
		if (a[i].l > r) {
			r = a[i].r;
			z++;
		} else if (a[i].r < r) {
			r = a[i].r;
		}
	}
	cout << z << '\n';
}