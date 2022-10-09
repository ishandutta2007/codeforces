// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int inf = 123123123;

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;

		int kec = count(begin(s), end(s), '1'), sol = inf;

		for (int r=0; r<k; r++) {
			int thiskec = 0, d1 = 0, d2 = 0, d3 = inf;
			for (int i=r; i<n; i+=k) {
				int e1 = inf, e2 = inf, e3 = inf;
				if (s[i] == '1') {
					mn(e1, d1 + 1);
					mn(e2, d1);
					mn(e2, d2);
					mn(e3, d2 + 1);
					mn(e3, d3 + 1);
					thiskec++;
				} else {
					mn(e1, d1);
					mn(e2, d1 + 1);
					mn(e2, d2 + 1);
					mn(e3, d2);
					mn(e3, d3);
				}

				d1 = e1;
				d2 = e2;
				d3 = e3;
			}

			sol = min(sol, kec - thiskec + min(d2, d3));
		}

		cout << sol << '\n';
	}

}