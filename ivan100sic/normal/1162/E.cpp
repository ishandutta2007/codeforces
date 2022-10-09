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

	int n;
	cin >> n;
	int k = 0, z = 123123123;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		if (x < z) {
			z = x;
			k = 1;
		} else if (x == z) {
			k++;
		}
	}
	cout << (k <= n/2 ? "Alice\n" : "Bob\n");
}