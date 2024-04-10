#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[105], n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	for (int d=100; d>0; d--) {
		int k = 0;
		for (int i=1; i<=100; i++)
			k += c[i] / d;
		if (k >= n)
			return cout << d, 0;
	}
	cout << 0;
}