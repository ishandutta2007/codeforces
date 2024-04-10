// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

typedef array<ll, 4> ar;

ar no() {
	ar a;
	a[0] = a[1] = a[2] = a[3] = -1e9;
	return a;
}

int n, k;
int c[1 << 17];

void mx(ll& x, ll y) {
	x = max(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;
	while (k--) {
		int x;
		cin >> x;
		c[x-1] = 1;
	}

	vector<ar> b, b2;

	int m = 1 << (n-1);
	for (int i=0; i<2*m; i+=2) {
		if (c[i] == c[i+1]) {
			ar a = no();
			a[c[i]*3] = c[i];
			b.push_back(a);
		} else {
			ar a = no();
			a[1] = a[2] = 1;
			b.push_back(a);
		}
	}

	while (m > 1) {
		b2 = {};
		for (int i=0; i<m; i+=2) {
			ar tgt = no();
			for (int p=0; p<2; p++)
			for (int q=0; q<2; q++)
			for (int r=0; r<2; r++)
			for (int s=0; s<2; s++)
			{
				ll v0 = b[i][p+2*q] + b[i+1][r+2*s];
				// strategije
				for (int x=0; x<2; x++)
				for (int y=0; y<2; y++)
				for (int z=0; z<2; z++)
				{
					int d = (p|r) + (q|s);
					int u1 = x?p:r;
					int l0 = x?r:p;
					int l1 = y?q:s;
					d += (l0|l1);
					int l2 = z?l0:l1;
					mx(tgt[u1+2*l2], v0 + d);
				}
			}
			b2.push_back(tgt);
		}
		b = b2;
		m /= 2;
	}

	ll sol = -1e9;
	for (int x=0; x<2; x++)
	for (int y=0; y<2; y++)
	{
		mx(sol, b[0][x+2*y] + (x|y));
	}

	cout << sol << '\n';
}