#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

const int LIMIT = 300;

int n;
int a[100005];
int d[100005][LIMIT+5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int k=1; k<=LIMIT; k++) {
		for (int i=n; i>=1; i--) {
			int q = i + a[i] + k;
			if (q > n) {
				d[i][k] = 1;
			} else {
				d[i][k] = d[q][k] + 1;
			}
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int p, k;
		cin >> p >> k;

		if (k <= LIMIT) {
			cout << d[p][k] << '\n';
		} else {
			int c = 0;
			while (p <= n) {
				p = p + a[p] + k;
				c++;
			}
			cout << c << '\n';
		}			
	}
}