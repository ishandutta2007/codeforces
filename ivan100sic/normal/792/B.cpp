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

int n, k, m;
int b[105];

int korak(int x) {
	do {
		x++;
		if (x == n) {
			x = 0;
		}
	} while (b[x] == 0);
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		b[i] = i+1;
	}
	m = n;
	int x = 0;
	for (int i=0; i<k; i++) {
		int a;
		cin >> a;

		a %= m;
		while (a--) {
			x = korak(x);
		}

		cout << b[x] << ' ';
		b[x] = 0;
		x = korak(x);
		m--;
	}
}