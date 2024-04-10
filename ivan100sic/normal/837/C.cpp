#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
using namespace std;

bool ok(int a, int b, int x, int y) {
	return (x <= a && y <= b) || (y <= a && x <= b);
}

int n, a, b;
int x[105], y[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
	}

	int sol = 0;

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {

			// split a
			for (int aa=1; aa<a; aa++) {
				if (ok(aa, b, x[i], y[i]) && ok(a-aa, b, x[j], y[j])) {
					sol = max(sol, x[i]*y[i] + x[j]*y[j]);
				}
			}

			// split b
			for (int bb=1; bb<b; bb++) {
				if (ok(a, bb, x[i], y[i]) && ok(a, b-bb, x[j], y[j])) {
					sol = max(sol, x[i]*y[i] + x[j]*y[j]);
				}
			}
		}
	}

	cout << sol;

}