#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[200005], n, s, g0;
int c[200005];
int d[200005];
int e[200005];

int main() {
	cin >> n >> s;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	if (n == 1) {
		if (a[1] == 0) {
			cout << 0;
		} else {
			cout << 1;
		}
		return 0;
	}

	int sef_ludak = 0;

	int zero_wrong = 0;
	for (int i=1; i<=n; i++) {
		if ((a[i] == 0) && (i != s)) {
			zero_wrong++;
		}
		if (i == s) {
			if (a[i] != 0) {
				sef_ludak = 1;
			}
			a[i] = 0;
		}
		if (a[i] > 0) {
			g0++;
			c[a[i]]++;
		}
	}

	for (int i=1; i<=n; i++) {
		e[i] = e[i-1] + c[i];
		if (c[i] > 1) {
			d[i] = c[i] - 1;
		}
		d[i] += d[i-1];

		if (c[i] == 0) {
			c[i] = 1;
		} else {
			c[i] = 0;
		}
		c[i] += c[i-1];
	}

	int sol = n;

	for (int h=1; h<=n; h++) {
		// svi koji su preveliki:
		int preveliki = g0 - e[h];

		int supernormalni = d[h];

		// treba promeniti sve prevelike od kojih ce neki otici da popune rupe
		int rupe = c[h];

		//cerr << "h : " << h << " preveliki : " << preveliki;
		//cerr << " rupe : " << rupe << " ludaci : " << zero_wrong << '\n';

		int promene = 0;
		int delta = min(preveliki, rupe);

		promene += delta;
		rupe -= delta;
		preveliki -= delta;

		int ludaci = zero_wrong;
		delta = min(ludaci, rupe);

		promene += delta;
		ludaci -= delta;
		rupe -= delta;

		delta = min(supernormalni, rupe);

		promene += delta;
		supernormalni -= delta;
		rupe -= delta;

		if (rupe > 0) {
			continue;
		}

		promene += ludaci + preveliki;

		// cerr << "h : " << h << " promene : " << promene << '\n';

		sol = min(sol, promene);
	}

	cout << sol + sef_ludak;
}