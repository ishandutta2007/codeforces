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

	int n, d=0;
	ll x;
	cin >> n >> x;
	while (n--) {
		char a;
		int b;
		cin >> a >> b;
		if (a == '+') {
			x += b;
		} else {
			if (x >= b) {
				x -= b;
			} else {
				d++;
			}
		}
	}
	cout << x << ' ' << d << '\n';
}