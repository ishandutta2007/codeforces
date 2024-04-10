#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, x, t = 1, z = 0;
	cin >> n >> x;
	while (n--) {
		int l, r;
		cin >> l >> r;
		int w = (l - t) / x;
		t += w * x;
		z += r - t + 1;
		t = r + 1;
	}
	cout << z << '\n';
}