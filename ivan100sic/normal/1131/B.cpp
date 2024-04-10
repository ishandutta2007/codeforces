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

	int n, z=1;
	int a=0, b=0;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		if (a == b)
			z--;
		if (a >= b && x >= y) {
			z += max(0, y-a+1);
		} else if (a <= b && x <= y) {
			z += max(0, x-b+1);
		} else {
			z += 1 + min(x-a, y-b);
		}
		a = x;
		b = y;
	}
	cout << z << '\n';
}