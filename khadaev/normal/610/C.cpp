#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < (1 << k); ++i) {
		for (int j = 0; j < (1 << k); ++j)
			cout << ((__builtin_popcount(i & j) % 2) ? '*' : '+');
		cout << '\n';
	}
}