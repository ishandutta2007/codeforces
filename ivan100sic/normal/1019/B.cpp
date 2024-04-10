#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int, int> kes;
int n;

int ask(int x) {
	x %= 2*n;
	if (x == 0)
		x = 2*n;

	if (kes.count(x))
		return kes[x];

	int y;
	cout << "? " << x << '\n' << flush;
	cin >> y;
	kes[x] = y;
	return y;
}

void ans(int x) {
	cout << "! " << x << '\n' << flush;
	exit(0);
}

int znak(int x) {
	if (x < 0)
		return -1;
	else if (x > 0)
		return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	n /= 2;

	if ((ask(1) - ask(n+1)) % 2 != 0)
		ans(-1);
	
	int b_lo = ask(1) - ask(n+1);
	int b_hi = ask(n+1) - ask(2*n+1);

	int lo = 1, hi = n+1;

	if (b_lo == 0)
		ans(1);
	
	while (1) {
		int mid = (lo + hi) / 2;
		int b_mid = ask(mid) - ask(mid + n);

		if (znak(b_mid) == 0)
			ans(mid);

		if (znak(b_mid) == znak(b_lo)) {
			b_lo = b_mid;
			lo = mid;
		} else {
			b_hi = b_mid;
			hi = mid;
		}
	}

	cerr << b_lo << ' ' << b_hi << '\n';

}