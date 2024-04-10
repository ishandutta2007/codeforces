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

	int n, a=0, b=0, c=0, bad = 0;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x == 25) {
			a++;
		} else if (x == 50) {
			if (a == 0) {
				bad = 1;
			} else {
				a--;
				b++;
			}
		} else if (x == 100) {
			if (b == 0) {
				if (a < 3) {
					bad = 1;
				} else {
					a -= 3;
				}
			} else {
				b--;
				if (a == 0) {
					bad = 1;
				} else {
					a--;
				}
			}
			c++;
		}
	}
	cout << (bad ? "NO\n" : "YES\n");
}