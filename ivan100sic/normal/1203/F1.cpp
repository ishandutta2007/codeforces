#include <bits/stdc++.h>
using namespace std;

struct stvar {
	int a, b;
	
	bool operator< (const stvar& o) const {
		int c = o.a;
		int d = o.b;
		if ((b < 0) != (d < 0))
			return b > d;
		if (b >= 0)
			return a < c;
		else
			return a+b > c+d;
	}
};

int d[105][70005];

int main() {
	int n, r;
	cin >> n >> r;
	vector<stvar> a(n);
	for (stvar& x : a)
		cin >> x.a >> x.b;
	sort(begin(a), end(a));
	memset(d, 255, sizeof(d));
	d[0][r] = 0;
	for (int i=0; i<n; i++) {
		int x = a[i].a;
		int y = a[i].b;
		// cout << "-- " << x << ' ' << y << '\n';
		for (int j=max(x, -y); j<=60000; j++) {
			if (d[i][j] != -1)
				d[i+1][j+y] = max(d[i+1][j+y], d[i][j] + 1);
		}
		for (int j=0; j<=60000; j++)
			if (d[i][j] != -1)
				d[i+1][j] = max(d[i+1][j], d[i][j]);
	}
	int z = *max_element(d[n], d[n]+60001);
	cout << (z == n ? "YES\n" : "NO\n");
	// cout << z << '\n';
}