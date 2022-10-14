#include <bits/stdc++.h>
using namespace std;

int n1, n2, k1, k2, a[2][101][101][12];

int f(bool type, int l1, int l2, int streak) {
	if (l1 <= 0 && l2 <= 0)
		return l1 == 0 && l2 == 0;
	if (a[type][l1][l2][streak] != -1)
		return a[type][l1][l2][streak];
	a[type][l1][l2][streak] = 0;
	if (type) {
		if (l1 > 0 && streak < k1) {
			a[type][l1][l2][streak] += f(type, l1 - 1, l2, streak + 1);
			a[type][l1][l2][streak] %= 100000000;
		}
		if(l2)
			a[type][l1][l2][streak] += f(!type, l1, l2 - 1, 1);
		a[type][l1][l2][streak] %= 100000000;
	} else {
		if (l2 > 0 && streak < k2) {
			a[type][l1][l2][streak] += f(type, l1, l2 - 1, streak + 1);
			a[type][l1][l2][streak] %= 100000000;
		}
		if(l1)
			a[type][l1][l2][streak] += f(!type, l1 - 1, l2, 1);
		a[type][l1][l2][streak] %= 100000000;
	}
	return a[type][l1][l2][streak];
}

int main() {
	memset(a, -1, sizeof a);
	cin >> n1 >> n2 >> k1 >> k2;
	cout << f(1, n1, n2, 0)%100000000;
}