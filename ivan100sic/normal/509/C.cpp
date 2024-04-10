// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int n = 333;

string daj(string a, int m) {
	int spre = 0;
	for (int i=0; i<n; i++)
		spre += a[i];

	for (int i=n-1; i>=0; i--) {
		// ova ce da bude kriticna cifra
		spre -= a[i];

		if (a[i] < 9) {
			int lo = spre + a[i] + 1;
			int hi = spre + 9 * (n-i);

			if (lo <= m && m <= hi) {
				string b = a;
				int siz = spre;
				for (int j=i; j<n; j++) {
					int ld = j == i ? a[i] + 1 : 0;
					int hd = 9;
					for (int d=ld; d<=hd; d++) {
						int lo = siz + d;
						int hi = siz + d + 9 * (n-j-1);
						if (lo <= m && m <= hi) {
							b[j] = d;
							break;
						}
					}
					siz += b[j];
				}
				return b;
			}
		}
	}

	return a;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int q;
	cin >> q;
	string a(n, 0);

	while (q--) {
		int m;
		cin >> m;
		a = daj(a, m);
		for (int i=0, j=0; i<n; i++) {
			j |= a[i];
			if (j)
				cout << int(a[i]);
		}
		cout << '\n';
	}
}