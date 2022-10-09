#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int gcd(int a, int b) {
	int t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int x[1005], y[1005], s, n;
int ded[1005];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> n;

	for (int i=1; i<=n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i=1; i<=2*n; i++) {
		for (int j=1; j<=n; j++) {
			if (!ded[j] && s > x[j]) {
				s += y[j];
				ded[j] = 1;
			}
		}
	}

	cout << (accumulate(ded+1, ded+n+1, 0) == n ? "YES" : "NO");

}