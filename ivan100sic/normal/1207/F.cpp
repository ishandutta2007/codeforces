#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[500005];
int s[707][707];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			a[x] += y;
			for (int q=1; q<=700; q++)
				s[q][x%q] += y;
		} else if (x > 700) {
			int z = 0;
			for (int i=y; i<=500000; i+=x)
				z += a[i];
			cout << z << '\n';
		} else {
			cout << s[x][y] << '\n';
		}
	}
}