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

	int n, m, k, z=0;
	cin >> n >> m >> k;
	while (n--) {
		int x;
		cin >> x;
		if (x == 1) {
			if (m == 0)
				z++;
			else
				m--;
		} else {
			if (k > 0)
				k--;
			else if (m > 0)
				m--;
			else
				z++;
		}
	}
	cout << z << '\n';
}