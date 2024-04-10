#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int x[205], y[205];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int z = 0;
	for (int i=0; i<n; i++)
		cin >> x[i] >> y[i];
	for (int i=0; i<n; i++) {
		int m = 0;
		for (int j=0; j<n; j++) {
			if (x[j] > x[i] && y[j] == y[i])
				m |= 1;
			if (x[j] < x[i] && y[j] == y[i])
				m |= 2;
			if (y[j] > y[i] && x[j] == x[i])
				m |= 4;
			if (y[j] < y[i] && x[j] == x[i])
				m |= 8;
		}
		if (m == 15)
			z++;
	}
	cout << z << '\n';
}