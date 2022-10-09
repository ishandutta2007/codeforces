#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s;
int d[1 << 20];
int a[1 << 20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	int n = s.size();
	d[0] = 1;
	for (int i=0; i<=n; i++) {
		int x = 0;
		for (int j=1; j+i<=n; j++) {
			int c = 1 << (s[i+j-1] - 'a');
			if (x & c) {
				break;
			} else {
				x |= c;
				d[x] = 1;
			}
		}
	}
	for (int i=0; i<(1<<20); i++)
		if (d[i])
			a[i] = __builtin_popcount(i);
		else
			a[i] = -123123;

	for (int i=1; i<(1<<20); i<<=1) {
		for (int j=0; j<(1<<20); j++) {
			if (j & i) {
				a[j] = max(a[j], a[j-i]);
			}
		}
	}

	int z = 0;
	for (int i=0; i<(1<<20); i++) {
		if (d[i]) {
			z = max(z, __builtin_popcount(i) + a[(1<<20)-1-i]);
		}
	}
	cout << z << '\n';
}