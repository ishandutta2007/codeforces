#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];
int r[100005], q[100005];
int b[100005], c[100005];

struct cmp {
	bool operator() (int x, int y) const {
		return a[x] < a[y];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		r[i] = i;
	}
	if (n == 1) {
		cout << "YES\n0\n" << a[0] << '\n';
		return 0;
	}
	sort(r, r+n, cmp());
	for (int i=0; i<n; i++)
		q[r[i]] = i;
	// r je permutacija koju treba da primenis na kraju
	sort(a, a+n);
	int m = n - (n+2)/3;
	memset(b, 0xff, sizeof(b));
	memset(c, 0xff, sizeof(c));
	int u = n-m;

	for (int i=0; i<u; i++)
		b[i] = i;
	for (int i=u; i<n; i++)
		c[i] = n-1-i;
	for (int i=2*u; i<n; i++)
		b[i] = n-i+m;
	reverse(c+u, c+2*u);

	for (int i=0; i<n; i++) {
		if (b[i] == -1) {
			b[i] = a[i] - c[i];
		} else if (c[i] == -1) {
			c[i] = a[i] - b[i];
		} else {
			b[i] = a[i] - c[i];
		}
	}
	cout << "YES\n";
	for (int i=0; i<n; i++)
		cout << b[q[i]] << " \n"[i == n-1];
	for (int i=0; i<n; i++)
		cout << c[q[i]] << " \n"[i == n-1];
}

/*
0 1 2 3 4 5 6 7 8 9 10 11 12
0 1 2 3 4           5 6 7 8
          8 7 6 5 4 3 2 1 0

*/