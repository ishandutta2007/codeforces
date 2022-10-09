#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int c[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;

	for (int i=k; i<=d; i+=k) {
		c[i] = 1;
	}

	for (int i=l; i<=d; i+=l) {
		c[i] = 1;
	}

	for (int i=m; i<=d; i+=m) {
		c[i] = 1;
	}

	for (int i=n; i<=d; i+=n) {
		c[i] = 1;
	}

	cout << accumulate(c+1, c+d+1, 0);
}