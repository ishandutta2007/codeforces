#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int H = 262144;

ll a[2*H], b[2*H];

void push(int x) {
	a[x] += b[x];
	if (x < H) {
		b[2*x] += b[x];
		b[2*x+1] += b[x];
	}
	b[x] = 0;
}

void dodaj(int l, int r, int v, int x, int xl, int xr) {
	if (r < xl || xr < l) {
		push(x);
		return;
	}
	if (l <= xl && xr <= r) {
		b[x] += v;
		push(x);
		return;
	}
	push(x);
	int xm = (xl + xr) >> 1;
	dodaj(l, r, v, 2*x, xl, xm);
	dodaj(l, r, v, 2*x+1, xm+1, xr);
	a[x] = min(a[2*x], a[2*x+1]);
}

ll citaj(int l, int r, int x, int xl, int xr) {
	push(x);
	if (r < xl || xr < l)
		return 123123123123123123ll;
	if (l <= xl && xr <= r)
		return a[x];
	int xm = (xl + xr) >> 1;
	return min(citaj(l, r, 2*x, xl, xm), citaj(l, r, 2*x+1, xm+1, xr));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		dodaj(i, i, x, 1, 0, H-1);
	}
	int q;
	cin >> q;
	string s;
	getline(cin, s);
	while (q--) {
		getline(cin, s);
		int a, b, c = -1123123123;
		istringstream iss(s);
		iss >> a >> b >> c;
		if (c == -1123123123) {
			ll z;
			if (a <= b) {
				z = citaj(a, b, 1, 0, H-1);
			} else {
				z = citaj(a, n-1, 1, 0, H-1);
				z = min(z, citaj(0, b, 1, 0, H-1));
			}
			cout << z << '\n';
		} else {
			if (a <= b) {
				dodaj(a,  b, c, 1, 0, H-1);
			} else {
				dodaj(a, n-1, c, 1, 0, H-1);
				dodaj(0,  b, c,  1, 0, H-1);
			}
		}
	}
}