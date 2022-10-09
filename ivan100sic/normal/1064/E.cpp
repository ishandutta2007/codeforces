#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int ask(int x, int y) {
	cout << x << ' ' << y << '\n' << flush;
	string s;
	cin >> s;
	return s == "black";
}

void ans(int x1, int y1, int x2, int y2) {
	cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n' << flush;
	exit(0);
}

int boje[33];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	int l = 0, r = 1e9;

	if (n == 1) {
		ask(0, 0);
		ans(1, 0, 0, 1);
	}

	boje[1] = ask(0, 1);

	int stanje = 0;

	for (int i=2; i<=n; i++) {
		if (stanje == 0) {
			int mid = (l+r) >> 1;
			boje[i] = ask(mid, 1);
			if (boje[i] == boje[1]) {
				l = mid;
			} else {
				r = mid;
				stanje = 1;
			}
		} else {
			int mid = (l+r) >> 1;
			boje[i] = ask(mid, 1);
			if (boje[i] == boje[1]) {
				l = mid;
			} else {
				r = mid;
			}
		} //wut
	}

	ans(l, 0, r, 2);
}