#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct par {
	int a, b;
	par(int x=0, int y=0) : a(x), b(y) {
		if (a > b)
			swap(a, b);
	}
};

par spoji(par a, par b) {
	int c[4] = {a.a, a.b, b.a, b.b};
	sort(c, c+4);
	return par(c[2], c[3]);
}

int n;
int a[1000005];
par s[1 << 21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		s[a[i]] = spoji(s[a[i]], par(0, i));
	}

	for (int i=0; i<21; i++) {
		for (int j=0; j<(1<<21); j++) {
			if (j & (1 << i)) {
				s[j - (1<<i)] = spoji(s[j - (1<<i)], s[j]);
			}
		}
	}

	int z = 0;
	for (int i=n-2; i>=1; i--) {
		int x = a[i], moze = 0, pitam = 0;
		for (int j=20; j>=0; j--) {
			if (x & (1 << j)) {
				moze |= 1 << j;
			} else {
				int t = pitam | (1 << j);
				if (s[t].a > i) {
					pitam = t;
					moze |= 1 << j;
				} else {
					// ne pitam, idi dalje
				}
			}
		}
		z = max(z, moze);
	}
	cout << z << '\n';
}