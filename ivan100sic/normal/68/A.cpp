#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int p[4];
int a, b, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b;
	for (int x=a; x<=b; x++) {
		sort(p, p+4);
		int d = 0;
		for (int i=0; i<24; i++, next_permutation(p, p+4)) {
			if (x % p[0] % p[1] % p[2] % p[3] == x)
				d++;
		}
		if (d >= 7)
			c++;
	}
	cout << c;
}