#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[200005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	int p = 1;
	int l = 0, r = 0, z = 0;

	while (p != 200001) {
		if (c[p] == 0) {
			p++;
		} else {
			int q = p+1;
			while (c[q] > 1) {
				q++;
			}
			if (c[q] == 0) {
				q--;
			}
			int zz = accumulate(c+p, c+q+1, 0);

			if (zz > z) {
				l = p;
				r = q;
				z = zz;
			}

			if (p == q)
				p = q+1;
			else
				p = q;
		}
	}

	cout << z << '\n';
	for (int i=l; i<=r; i++)
		cout << i << ' ';
	for (int i=r; i>=l; i--) {
		for (int t=0; t<c[i]-1; t++)
			cout << i << ' ';
	}
	cout << '\n';
}