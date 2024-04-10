#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int r[55], c[55], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n*n; i++) {
		int x, y;
		cin >> x >> y;
		if (r[x] + c[y] == 0) {
			r[x] = c[y] = 1;
			cout << i+1 << ' ';
		}
	}
	cout << '\n';
}