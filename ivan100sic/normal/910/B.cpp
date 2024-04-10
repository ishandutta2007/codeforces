#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, a, b;
int c[6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b;
	c[0] = c[1] = c[2] = c[3] = a;
	c[4] = c[5] = b;

	sort(c, c+6);

	int z = 1231231;
	do {
		int w = 0;
		int used = 0;
		for (int i=0; i<6; i++) {
			if (c[i] <= w) {
				w -= c[i];
			} else {
				w = n;
				used += 1;
				w -= c[i];
			}
		}
		z = min(z, used);
	} while (next_permutation(c, c+6));
	cout << z << '\n';
}