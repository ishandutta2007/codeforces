#include <bits/stdc++.h>
using namespace std;

int rek(int cl, int lvl, int xp, int& xpnd) {
	if (!lvl) {
		xpnd += cl^xp;
		return cl == xp;
	} else {
		int t = rek(cl^1, lvl-1, xp  , xpnd)^1;
		t    ^= rek(cl  , lvl-1, xp^t, xpnd);
		return t;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	int md = 0, sz = 1;
	while (2*sz+1 <= n) {
		md++;
		sz = 2*sz+1;
	}
	int e0=0, e1=0;
	rek(0, md, 1, e0);
	rek(1, md, 1, e1);
	cout << (n-sz==e0) + (n-sz==e1) << '\n';
}