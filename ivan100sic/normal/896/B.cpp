#include <bits/stdc++.h>
using namespace std;

int n, m, c, midc;
int a[1005];

void did_we_win() {
	for (int i=1; i<=n; i++) {
		if (a[i] == 0) {
			return;
		}
	}
	for (int i=2; i<=n; i++) {
		if (a[i-1] > a[i]) {
			return;
		}
	}
	
	// done
	exit(0);
}

int vl, vr, pl, pr;

int place(int x) {
	// biraj stranu
	if (x - vl <= vr - x) {
		// levo
		for (int i=1; i<=pl; i++) {
			if (x < a[i]) {
				a[i] = x;
				return i;
			}
		}
		// nista?
		a[++pl] = x;
		return pl;
	} else {
		for (int i=n; i>=pr; i--) {
			if (x > a[i]) {
				a[i] = x;
				return i;
			}
		}
		a[--pr] = x;
		return pr; 
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> c;

	if (n == 1) {
		int x;
		cin >> x;
		cout << "1\n" << flush;
		return 0;
	}

	vl = 1;
	vr = c;
	pl = 0;
	pr = n+1;
	a[0] = 1;
	a[n+1] = c;

	while (1) {
		int x;
		cin >> x;
		cout << place(x) << '\n' << flush;
		vl = a[pl];
		vr = a[pr];
		did_we_win();
	}
}