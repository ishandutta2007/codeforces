#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dgts(int x) {
	int c = 0;
	if (x == 0) return 1;
	while (x > 0) {
		x /= 7;
		c++;
	}
	return c;
}

int pw(int x, int y) {
	int t = 1;
	while (y--) t *= x;
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, u = 0;
	cin >> n >> m;
	int a = dgts(n-1), b = dgts(m-1);

	if (a + b > 7) {
		cout << "0\n";
		return 0;
	}

	for (int i=0; i<pw(7, a); i++) {
		for (int j=0; j<pw(7, b); j++) {

			set<char> s;
			int z = i;
			for (int t=0; t<a; t++) {
				s.insert(z % 7);
				z /= 7;
			}
			z = j;
			for (int t=0; t<b; t++) {
				s.insert(z % 7);
				z /= 7;
			}
			if ((int)s.size() == a+b && i < n && j < m)
				u++;
		}
	}
	cout << u << '\n';
}