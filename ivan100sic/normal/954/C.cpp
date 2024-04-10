// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void no() {
	cout << "NO\n";
	exit(0);
}

int n;
int a[200005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	int y = -1;
	for (int i=1; i<n; i++) {
		int d = abs(a[i] - a[i-1]);
		if (d == 0)
			no();
		if (d > 1) {
			if (y == -1)
				y = d;
			else if (y != d)
				no();
		}
	}

	if (y == -1)
		y = 1;
	else {
		for (int i=1; i<n; i++) {
			int d = abs(a[i] - a[i-1]);
			if (d == 1) {
				if ((a[i]-1) / y != (a[i-1]-1) / y)
					no();
			}
		}
	}

	cout << "YES\n1000000000 " << y << '\n';
}