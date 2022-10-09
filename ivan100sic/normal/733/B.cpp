#include <iostream>
using namespace std;

int l[5000005], r[5000005], L, R, opt, pos = 0;

int aps(int x) {
	return x < 0 ? -x : x;
}

int main() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> l[i] >> r[i];
		L += l[i];
		R += r[i];
	}
	opt = aps(L - R);
	for (int i=1; i<=n; i++) {
		int Lp = L - l[i] + r[i];
		int Rp = R - r[i] + l[i];
		int c = aps(Lp - Rp);
		if (c > opt) {
			opt = c;
			pos = i;
		}
	}
	cout << pos;
}