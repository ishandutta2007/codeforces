// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, x, y, ao=-1, bo=-1;
		cin >> n >> x >> y;
		int opt = 123123123;
		for (int a=1; a<=50; a++) {
			for (int b=1; b<=50; b++) {
				int m = 0;
				for (int i=0; i<n; i++) {
					if (a+b*i == x) m |= 1;
					if (a+b*i == y) m |= 2;
				}

				if (m == 3) {
					if (a+b*(n-1) < opt) {
						opt = a+b*(n-1);
						ao = a;
						bo = b;
					}
				}
			}
		}

		for (int i=0; i<n; i++) {
			cout << ao+bo*i << " \n"[i == n-1];
		}
	}
}