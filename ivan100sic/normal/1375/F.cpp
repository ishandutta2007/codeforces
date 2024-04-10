// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll a[3];
int lastmove;

int rd() {
	int x;
	cin >> x;
	if (x == 0) {
		exit(0);
	}
	return lastmove = x-1;
}

void finishhim() {
	ll mx = max({a[0], a[1], a[2]});
	ll mn = min({a[0], a[1], a[2]});
	ll md = a[0] + a[1] + a[2] - mx - mn;

	ll diff = 2*mx - mn - md;
	cout << diff << '\n' << flush;
	a[rd()] += diff;

	mx = max({a[0], a[1], a[2]});
	mn = min({a[0], a[1], a[2]});
	diff = (mx - mn) / 2;
	cout << diff << '\n' << flush;
	a[rd()] += diff;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> a[0] >> a[1] >> a[2];

	cout << "First\n" << flush;

	// nateraj ga da zadnji bude
	ll diff = 3213213213;
	cout << diff << '\n' << flush;
	a[rd()] += diff;
	finishhim();
}