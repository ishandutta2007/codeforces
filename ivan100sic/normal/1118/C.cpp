#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int c[1005];
int a[25][25];
basic_string<int> e1, e2, e4;

void no() {
	cout << "nO\n";
	exit(0);
}

void ok() {
	cout << "YeS\n";
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cout << a[i][j] << " \n"[j == n-1];
	exit(0);
}

int get2() {
	if (e2.size() == 0) {
		int x = e4.back(); e4.pop_back();
		e2 += x;
		return x;
	} else {
		int x = e2.back();
		e2.pop_back();
		return x;
	}
}

int get4() {
	if (e4.size() == 0) {
		no(); return -1;
	} else {
		int x = e4.back();
		e4.pop_back();
		return x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n*n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	for (int i=1; i<=1000; i++) {
		while (c[i] >= 4) {
			e4 += i;
			c[i] -= 4;
		}
		if (c[i] >= 2) {
			e2 += i;
			c[i] -= 2;
		}
		if (c[i] >= 1) {
			e1 += i;
			c[i] -= 1;
		}
	}

	m = n - 1;

	if (n % 2 == 0) {
		// svi mora da budu 4
		if (e1.size() || e2.size())
			no();

		for (int i=0; i<n/2; i++)
			for (int j=0; j<n/2; j++) {
				int x = e4.back();
				e4.pop_back();
				a[i][j] = x;
				a[m-i][j] = x;
				a[i][m-j] = x;
				a[m-i][m-j] = x;
			}
	} else {
		if (e1.size() != 1)
			no();

		a[n/2][n/2] = e1.back(); e1.pop_back();

		for (int i=0; i<n/2; i++) {
			int x = get2();
			a[i][n/2] = x;
			a[m-i][n/2] = x;
			x = get2();
			a[n/2][i] = x;
			a[n/2][m-i] = x;
		}

		for (int i=0; i<n/2; i++) {
			for (int j=0; j<n/2; j++) {
				int x = get4();
				a[i][j] = x;
				a[m-i][j] = x;
				a[i][m-j] = x;
				a[m-i][m-j] = x;
			}
		}
	}

	ok();
}