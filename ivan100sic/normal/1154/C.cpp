#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int sta[7] = {0, 1, 2, 0, 2, 1, 0};

int f(int i, array<int, 3> a) {
	int k = min({a[0]/3, a[1]/2, a[2]/2});
	a[0] -= 3*k;
	a[1] -= 2*k;
	a[2] -= 2*k;
	int z = 7*k;
	while (1) {
		if (a[sta[i % 7]] > 0) {
			a[sta[i % 7]] -= 1;
			i++;
			z++;
		} else {
			break;
		}
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;
	int z = 0;
	for (int i=0; i<7; i++) {
		z = max(z, f(i, {a, b, c}));
	}
	cout << z << '\n';
}