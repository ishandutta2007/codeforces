#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, a[200005];
int gaus[20];

void gausclear() {
	fill(gaus, gaus+20, 0);
}

bool gausadd(int x) {
	for (int i=0; i<20; i++) {
		if (x & (1 << i)) {
			if (gaus[i] == 0) {
				gaus[i] = x;
				return true;
			} else {
				x ^= gaus[i];
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	for (int x=20; x>=0; x--) {
		// proveri da li moze da se dobije lin nez sis
		gausclear();
		basic_string<int> v;
		for (int i=0; i<n; i++) {
			if (a[i] < (1 << x)) {
				if (gausadd(a[i]))
					v += a[i];
			}
		}
		if ((int)v.size() == x) {
			cout << x << '\n';
			int z = 0;
			for (int i=1; i<=(1<<x); i++) {
				cout << z << ' ';
				if (i < (1<<x))
					z ^= v[31 - __builtin_clz(ld(i & -i))];
			}
			cout << '\n';
			return 0;
		}
	}
}