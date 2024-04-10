#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*

recimo da su oba pozitivna i x < y

|x-y| <= x <= y <= |x+y|

*/

bool inside(int x, int y) {
	int al = abs(x);
	int ar = abs(y);
	if (al > ar)
		swap(al, ar);
	int bl = abs(x-y);
	int br = abs(x+y);
	if (bl > br)
		swap(bl, br);
	return bl <= al && ar <= br;
}

bool ca(int x, int y) {
	if (abs(x) != abs(y))
		return abs(x) < abs(y);
	return x < y;
}

int n;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int x=-10; x<=10; x++) {
		for (int y=-10; y<=10; y++) {
			cerr << (inside(x, y) ? '#' : '.');
		}
		cerr << '\n';
	}

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n, ca);
	unique(a, a+n);
	int j = 0;
	ll z = 0;
	for (int i=0; i<n; i++) {
		while (j < i && abs(a[j])*2 < abs(a[i])) {
			j++;
		}
		// cerr << i << ' ' << j << ' ' << a[i] << '\n';
		z += i-j;
	}
	cout << z << '\n';
}